#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionRecord.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMissionRecord {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Tag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Weapon;
    FMissionRecord();
    ~FMissionRecord();
};
