#include "StoryConfig.h"
#include "ITRDefaults.h"

UStoryConfig::UStoryConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.StoryConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("EmptyCassette.Group"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("ChoiceKillSelfTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("ChoiceKillKatyaTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("ChoiceKillKatyaMonologueTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("ChoiceKillPresenceTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("ChoiceKillPresenceMonologueTag.TagName"), TEXT("None"));
}

TArray<FGameplayTag> UStoryConfig::ParseRecordsTags(TArray<FGameplayTag> ItemAdditionalTags) {
    return {};
}

bool UStoryConfig::IsJournalNote(const FGameplayTag& NoteID) const {
    return {};
}

bool UStoryConfig::HasNote(FGameplayTag NoteID) {
    return {};
}

bool UStoryConfig::HasMissionTip(FGameplayTag TipID) {
    return {};
}

FRecordSubtitle UStoryConfig::GetSubtitleForTime(FRecord Record, float TimeSeconds) {
    return {};
}

UStoryConfig* UStoryConfig::GetStoryConfig() {
    return {};
}

void UStoryConfig::GetRandomCassette(bool bMissingOnly, bool& bSuccess, FGameplayTag& CassetteTag, FDialogue& CassetteDialogue) {
}

void UStoryConfig::GetPaperNote(FGameplayTag NoteID, bool& bSuccess, FPaperNote& Note) {
}

FGameplayTag UStoryConfig::GetNPCJournalNote(const FGameplayTag& NpcID) const {
    return {};
}

void UStoryConfig::GetMissionTip(FGameplayTag TipID, bool& bSuccess, FRecord& Record) {
}

void UStoryConfig::GetKatyaMonologue(FGameplayTag Tag, bool& bSuccess, FDialogue& Monologue) {
}

void UStoryConfig::GetCassette(FGameplayTag CassetteTag, bool& bSuccess, FDialogue& CassetteDialogue) {
}

