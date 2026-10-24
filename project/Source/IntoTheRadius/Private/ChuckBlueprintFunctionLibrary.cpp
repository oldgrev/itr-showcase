#include "ChuckBlueprintFunctionLibrary.h"
#include "GameplayTagsManager.h"

FGameplayTag UGetTagFromString::GetTagFromString(FName TagName, FGameplayTag Tag)
{
    return UGameplayTagsManager::Get().RequestGameplayTag(TagName);
}
