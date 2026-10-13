// ITR Showcase: Blueprint generator (editor-only). Builds a Blueprint asset from a small JSON spec.
// Spec format: see Plugins/ItrShowcaseEditor/SPEC.md. Python: unreal.ItrShowcaseBPGen.generate_blueprint_from_spec(path)
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItrShowcaseBPGen.generated.h"

UCLASS()
class ITRSHOWCASEEDITOR_API UItrShowcaseBPGen : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * Creates (or resets and rebuilds in place) the Blueprint described by the JSON spec at JsonPath, compiles and saves it.
	 * Returns a report; the first line is "OK <asset>" or "ERROR <asset>". The report lists every compiler message and
	 * the bytecode size of each generated function.
	 */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|BPGen")
	static FString GenerateBlueprintFromSpec(const FString& JsonPath);
};
