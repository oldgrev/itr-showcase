#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "MinMaxFloat.h"
#include "NPCCloseCombatConfig.h"
#include "NPCFirearmConfig.h"
#include "NPCIdleConfig.h"
#include "NPCMeleeConfig.h"
#include "NPCPerceptionConfig.h"
#include "PRNPCInfo.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRNPCInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag NPCConfigID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<AActor> ActorClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText Name;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText Description;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat MaxHealthRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FName CritBoneName;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCIdleConfig IdleConfig;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCPerceptionConfig PerceptionConfig;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCPerceptionConfig ReducedPerceptionConfig;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCMeleeConfig MeleeConfig;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCFirearmConfig FirearmConfig;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat AttackMoveDilationAngle;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float LootPossibilityPercent;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag CoreItemTypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat FootstepNoiseRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool IsArmored;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCCloseCombatConfig CloseCombatConfig;
    FPRNPCInfo();
    ~FPRNPCInfo();
};
