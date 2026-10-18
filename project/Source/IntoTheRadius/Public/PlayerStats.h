#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsTuple.h"
#include "PlayerStats.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPlayerStats {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> Deaths;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTagsTuple> Kills;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<uint8> OfflineAchievements;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> CollectedItems;
    FPlayerStats();
    ~FPlayerStats();
};
