#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionBaseConfig.h"
#include "MissionTriggersConfig.h"
#include "TagToTagsList.h"
#include "MissionNormalConfig.generated.h"

class UMissionBaseHintObjectiveConfig;
class UMissionBaseObjectiveConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionNormalConfig : public UMissionBaseConfig {
    GENERATED_BODY()
public:
    UMissionNormalConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool CheckObjectives();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CooldownMissions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    TArray<UMissionBaseObjectiveConfig*> PrimaryObjectives;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    TArray<UMissionBaseObjectiveConfig*> SecondaryObjectives;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    TArray<UMissionBaseHintObjectiveConfig*> HintObjectives;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FGameplayTag, FGameplayTag> AdditionalCorpsePointsToLoot;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTagToTagsList> AdditionalPointsToNPCs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMissionTriggersConfig SuccessTriggers;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMissionTriggersConfig FailTriggers;
};
