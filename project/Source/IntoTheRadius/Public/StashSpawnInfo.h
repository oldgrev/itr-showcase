#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ActorSpawnInfo.h"
#include "StashSpawnInfo.generated.h"

class UPRItemConfig;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FStashSpawnInfo : public FActorSpawnInfo {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    float SpawnChange;
    UPROPERTY(BlueprintReadWrite)
    FString InstanceId;
    UPROPERTY(BlueprintReadWrite)
    int32 LoopPoints;
    UPROPERTY(BlueprintReadWrite)
    FGameplayTag LootTable;
    UPROPERTY(BlueprintReadWrite)
    TArray<UPRItemConfig*> LootConfigs;
    FStashSpawnInfo();
    ~FStashSpawnInfo();
};
