// ITR Showcase: T-116 asset audit helpers (editor-only). Recreates game assets from the data cue4export reads out of the cooked paks
// (tools/itr-showcase/audit) and dumps what the saved assets hold, in the same shape as the cooked data, for an exact comparison.
// Python: unreal.ItrShowcaseAudit.<function>. Every function returns a problem list ("" = no problems), never asserts.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItrShowcaseAudit.generated.h"

class UStaticMesh;
class UMaterialInstanceConstant;

class UMaterial;
class UMaterialExpression;

UCLASS()
class ITRSHOWCASEEDITOR_API UItrShowcaseAudit : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/** Sets every property in PropsJson (a JSON object: cooked property name -> value, see cue4export tree) on Obj. Strict: returns one line per
	 *  value or struct field that could not be set. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString ApplyProps(UObject* Obj, const FString& PropsJson);

	/** Creates (or rebuilds in place) the Texture2D at AssetPath (/Game/../Name) with its source = the 8-bit PNG (exact pixels, BGRA8, one mip;
	 *  no importer heuristics), then applies PropsJson. Not saved. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString CreateTexture2D(const FString& AssetPath, const FString& PngFile, const FString& PropsJson);

	/** Creates (or resets in place) an asset of ClassPath (/Script/Module.Class) at AssetPath and applies PropsJson. Not saved. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString CreateGeneric(const FString& AssetPath, const FString& ClassPath, const FString& PropsJson);

	/** Creates the asset at AssetPath (class ClassPath) and every subobject in SubobjectsJson ([{name, class, outer, path, props}], outers
	 *  first) with the same names, then sets every property (references inside the package resolve to the new subobjects) and finishes the
	 *  class (particle systems: module lists, sound cues: editor graph from the nodes). Not saved. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString CreatePackageGraph(const FString& AssetPath, const FString& ClassPath, const FString& PropsJson, const FString& SubobjectsJson);

	/** Creates the Blueprint struct at AssetPath with the game's members (FieldsJson [{name: "Friendly_N_GUID", specType}], exact names and
	 *  GUIDs, in order) and their default values (DefaultsJson {name: value}). Not saved. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString CreateUserDefinedStruct(const FString& AssetPath, const FString& FieldsJson, const FString& DefaultsJson);

	/** Creates (or resets in place) the material instance at AssetPath: Parent set the editor way, every parameter from PropsJson, static
	 *  permutation + base property overrides updated. Not saved. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString SetupMaterialInstance(const FString& AssetPath, const FString& PropsJson);

	/** Static mesh after the FBX import of every LOD: build settings, LOD screen sizes, material slots, sockets, body setup (simple collision
	 *  exactly as cooked) and the remaining properties from NodeJson (a cue4export tree node, references already mapped); rebuilds. Not saved. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString FinishStaticMesh(UStaticMesh* Mesh, const FString& NodeJson);

	/** JSON of what the asset at ObjectPath holds, comparable with the cooked data: props (every serialized, non-editor-only property; structs
	 *  carry "__nd" = fields that differ from their default) plus facts per type (texture: source + Windows cook result; mesh: per-LOD render
	 *  data, slots, sockets, body setup; materials: parameter names). */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString DumpAsset(const FString& ObjectPath);

	/** Connects output OutputName ("" = first) of Expression to the material input PropertyIndex (an EMaterialProperty value). For the inputs
	 *  Python cannot name: MP_WorldPositionOffset (12) and the other UMETA(Hidden) entries of the MaterialProperty enum (T-116 layered
	 *  masters). Returns "" or the problem. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Audit")
	static FString ConnectMaterialPropertyIndex(UMaterial* Material, UMaterialExpression* Expression, const FString& OutputName, int32 PropertyIndex);
};
