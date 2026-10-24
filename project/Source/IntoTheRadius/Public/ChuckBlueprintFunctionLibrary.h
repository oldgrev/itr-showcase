#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "ChuckBlueprintFunctionLibrary.generated.h"

// T-131: showcase generator helper (not in the game). Python: unreal.ChuckScripts.get_tag_from_string(name, unreal.GameplayTag()) -> the registered tag.
// FGameplayTag::TagName is read-only in Python, so the editor build step reaches tags through this function. Same class the g1 stub had (ScriptName ChuckScripts).
UCLASS(meta = (ScriptName = "ChuckScripts"))
class INTOTHERADIUS_API UGetTagFromString : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "Chuck", meta = (DisplayName = "ToTag (String)"))
    static FGameplayTag GetTagFromString(FName TagName, FGameplayTag Tag);
};
