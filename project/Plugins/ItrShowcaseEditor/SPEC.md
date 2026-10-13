# BPGen spec format (ItrShowcaseEditor)

`unreal.ItrShowcaseBPGen.generate_blueprint_from_spec(json_path)` creates the Blueprint, or resets and rebuilds it
in place when it already exists (placed instances keep pointing at it). Then it compiles and saves it, and returns a
report. The first line of the report is `OK <asset>` or `ERROR <asset>`, followed by every error, the compiler
warnings and errors, and the bytecode size of each generated function. The generated Blueprint references only the
classes and functions the spec names. Nothing from this plugin ends up in it.

```jsonc
{
  "asset":  "/Game/Mods/X/BP_Name",            // package path
  "parent": "/Script/Engine.Actor",            // class path or short name ("Actor")
  "components": [                              // SCS; the first scene component without "attach" becomes the root
    {"name": "Trigger", "class": "BoxComponent", "attach": "Root",
     "props": {"BoxExtent": "(X=70,Y=70,Z=100)", "StaticMesh": "/Engine/BasicShapes/Cube.Cube"}}   // T3D text or an object path
  ],
  "variables": [                               // types: bool byte int float name string text vector rotator transform
    {"name": "Target", "type": "object:Actor", //        linearcolor color struct:<S> object:<C> class:<C>, "[]" suffix = array
     "default": "", "editable": true, "category": "X", "tooltip": "..."}   // editable = instance-editable
  ],
  "nodes": [                                   // EventGraph; optional "pos": [x, y] (auto grid otherwise)
    {"id": "ov",  "op": "component_event", "component": "Trigger", "delegate": "OnComponentBeginOverlap"},
    {"id": "bp",  "op": "event", "event": "ReceiveBeginPlay"},           // override event (ReceiveTick, ...)
    {"id": "ce",  "op": "custom_event", "name": "Revert"},
    {"id": "f",   "op": "call", "function": "GameplayStatics:GetPlayerPawn", "pins": {"PlayerIndex": 0}},
    {"id": "g",   "op": "get", "var": "Target"},                         // "class": C for another class's member
    {"id": "s",   "op": "set", "var": "bReady", "pins": {"bReady": true}},
    {"id": "b",   "op": "branch"},  {"id": "q", "op": "sequence", "outputs": 3},  {"id": "me", "op": "self"},
    {"id": "c",   "op": "cast", "class": "Pawn", "pure": false},
    {"id": "m",   "op": "macro", "macro": "ForEachLoop"},                // StandardMacros (DoOnce, Gate, ForLoop, ...)
    {"id": "n",   "op": "node", "class": "K2Node_Select", "props": {}}   // any K2 node class; props = UPROPERTY T3D text
  ],
  "links": [["ov.then", "b.execute"], ["ov.OtherActor", "c.Object"]]     // "id.pin" output -> "id.pin" input
}
```

`call` with no class prefix looks the function up on the Blueprint itself. Array-library functions get a
`K2Node_CallArrayFunction`. Latent functions such as `KismetSystemLibrary:Delay` work.

Pins are matched by internal name first (`execute`, `then`, `self`, `ReturnValue`, parameter names), then without
case, then by display name (Branch `True`/`False`, Delay `Completed`). `exec`/`in` and `out` are aliases for
`execute`/`then`. If a pin isn't found, the error lists the pins the node has. Links are made before pin defaults, so
wildcard pins (macros, array functions) are resolved by the time their defaults are set.

## Additions (T-067, easter egg)

Top-level keys: `"requires": ["Other.json"]` (paths relative to this spec) generates those specs first, so this Blueprint can name their
classes (`object:/Game/.../BP_X.BP_X_C`); a spec is generated once per process and file time. A spec with no `nodes` needs no EventGraph, so
non-Actor parents work: `"parent": "/Script/Engine.SaveGame"` with only `variables` makes a SaveGame whose variables are saved by
`SaveGameToSlot`.

Ops and fields:
* `cast` with `"class": "VRGripInterface"` (interface) or any class path; `"class_cast": true` makes `K2Node_ClassDynamicCast`
  (input `Class`, output `As<Class>`). In links the cast result pin can be written `as` (first data output) instead of `AsBP_Name`.
* `message`: `{"op": "message", "function": "INPC:Alert"}` calls an interface function on any object (`K2Node_Message`; target pin `self`).
  A plain `call` of an interface function works on the output of a cast to that interface.
* `custom_event` may carry `"params": [{"name": "Stage", "type": "int"}]`. All custom events are created first and the Blueprint is compiled
  before the other nodes, so a `call` without a class prefix (`{"function": "SaveNow"}`) can call a custom event of the same Blueprint.
* `create_delegate`: `{"op": "create_delegate", "function": "MyEvent"}`, output `OutputDelegate` to a delegate pin
  (`KismetSystemLibrary:K2_SetTimerDelegate`). The function is bound after the links exist. Not used by the included specs (untested).
* Timers: `KismetSystemLibrary:K2_SetTimer` (link a `self` node to `Object`; returns an `FTimerHandle`, store it in a variable of type
  `struct:TimerHandle`) and `K2_ClearAndInvalidateTimerHandle` (`WorldContextObject`, `Handle`).
* Variable types additionally: `struct:TimerHandle`, arrays of anything (`object:/Script/Engine.Actor[]`, `vector[]`, `bool[]`, `string[]`).
* Pin defaults: integral JSON numbers become integer text (`5`, not `5.0`); soft object/class pins take a path without loading it
  (the asset need not exist in this project, e.g. a game asset). Game and function-library classes are named by short class name
  (`FLItems`, `FLSpawn`, `InventoryManager`, `VRGripInterface`, `IPRGameModeNative`) or `/Script/IntoTheRadius.<Name>`; a leading `I`
  is tolerated for interfaces.
* Runtime asset loading from the game without copying it: `KismetSystemLibrary:MakeSoftObjectPath` -> `Conv_SoftObjPathToSoftObjRef` ->
  `LoadAsset_Blocking` (and the `...SoftClassPath...` / `LoadClassAsset_Blocking` chain, then a `class_cast`).
* Spawning: `{"op": "node", "class": "K2Node_SpawnActorFromClass", "pins": {"CollisionHandlingOverride": "AdjustIfPossibleButAlwaysSpawn"}}`,
  link `Class` (a `class:` pin) and `SpawnTransform`; the result is `ReturnValue` (Actor).
* Pin names: after exact / case-insensitive / display name, a last pass compares letters and digits only (`AsBP_X` == `AsBP X`).
* Exec bridging: an exec link into a node that has no exec pins at all (pure; a `const` BlueprintCallable function is pure in the editor; macro nodes such as `ForEachLoop`, whose exec pins are named `Exec`/`LoopBody`/`Completed`, are not pure) is
  joined past that node: `a.then -> n.execute` and `n.then -> b.execute` become `a.then -> b.execute`. The report lists these as notes.
* Random, string and array library functions need nothing special: `KismetMathLibrary:RandomFloatInRange` / `RandomIntegerInRange` /
  `RandomBoolWithWeight`, `KismetStringLibrary:ToLower` / `Trim` / `EqualEqual_StriStri` / `Contains`, `KismetArrayLibrary:Array_Add` /
  `Array_Get` / `Array_Set` / `Array_Clear` / `Array_Contains`; the macros `ForEachLoop`, `ForLoop`, `ForLoopWithBreak` (pins `Exec`, `Break`,
  `LoopBody`, `Index`, `ArrayElement`, `Completed`).
