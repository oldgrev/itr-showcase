#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionAbstractObjectiveData.h"
#include "TagToTagsList.h"
#include "MissionKillNPCObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionKillNPCObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionKillNPCObjectiveData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    FString PointSpawnerID(FGameplayTag pointTag);

    UFUNCTION(BlueprintCallable)
    void MarkPointCleared(FGameplayTag pointTag);

    UPROPERTY(BlueprintReadOnly)
    TArray<FTagToTagsList> PointsToNPCs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnNPCsRadius;
    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> ClearedPoints;
};
