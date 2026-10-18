#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ConditionalPaperNote.h"
#include "Dialogue.h"
#include "DialoguesGroup.h"
#include "HostileDescription.h"
#include "IAsset.h"
#include "IPreparable.h"
#include "PaperNote.h"
#include "Record.h"
#include "RecordSubtitle.h"
#include "StoryConfig.generated.h"

class UPRItemConfig;
class USoundBase;
class UStoryConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UStoryConfig : public UDataAsset, public IIAsset, public IIPreparable {
    GENERATED_BODY()
public:
    UStoryConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    TArray<FGameplayTag> ParseRecordsTags(TArray<FGameplayTag> ItemAdditionalTags);

    UFUNCTION(BlueprintCallable)
    bool IsJournalNote(const FGameplayTag& NoteID) const;

    UFUNCTION(BlueprintPure)
    bool HasNote(FGameplayTag NoteID);

    UFUNCTION(BlueprintPure)
    bool HasMissionTip(FGameplayTag TipID);

    UFUNCTION(BlueprintPure)
    FRecordSubtitle GetSubtitleForTime(FRecord Record, float TimeSeconds);

    UFUNCTION(BlueprintPure)
    static UStoryConfig* GetStoryConfig();

    UFUNCTION(BlueprintCallable)
    void GetRandomCassette(bool bMissingOnly, bool& bSuccess, FGameplayTag& CassetteTag, FDialogue& CassetteDialogue);

    UFUNCTION(BlueprintCallable)
    void GetPaperNote(FGameplayTag NoteID, bool& bSuccess, FPaperNote& Note);

    UFUNCTION(BlueprintCallable)
    FGameplayTag GetNPCJournalNote(const FGameplayTag& NpcID) const;

    UFUNCTION(BlueprintPure)
    void GetMissionTip(FGameplayTag TipID, bool& bSuccess, FRecord& Record);

    UFUNCTION(BlueprintCallable)
    void GetKatyaMonologue(FGameplayTag Tag, bool& bSuccess, FDialogue& Monologue);

    UFUNCTION(BlueprintCallable)
    void GetCassette(FGameplayTag CassetteTag, bool& bSuccess, FDialogue& CassetteDialogue);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FDialoguesGroup> CassetteGroups;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FDialogue EmptyCassette;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FPaperNote> PaperNotes;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FConditionalPaperNote> ConditionalPaperNotes;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FHostileDescription> Monsters;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FHostileDescription> anomalies;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FHostileDescription> Other;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FRecord> MissionTips;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FDialogue> KatyaMonologues;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FDialogue> FinalDialogs;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    UPRItemConfig* FinalWeaponConfig;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ChoiceKillSelfTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ChoiceKillKatyaTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ChoiceKillKatyaMonologueTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ChoiceKillPresenceTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ChoiceKillPresenceMonologueTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> ItemTypeIDsToDestroyAfterFinale;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FDialogue> Epilogues;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FText> HintWeaponOnSafety;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FText> HintWeaponNotLoaded;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FText> HintWeaponCockTheBolt;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FText> HintWeaponJammed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FText> HintMagEmpty;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<USoundBase*> HintNoMissionTurretSound;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FText> HintNoMissionTurretSubtitle;
};
