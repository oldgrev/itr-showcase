#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "MinMaxFloat.h"
#include "MinMaxInt.h"
#include "PRLootEntryConfig.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPRLootEntryConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FGameplayTag ItemTag;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 LootPoints;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool RandomizeDurability;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FMinMaxFloat RandomDurability;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool ChangeLootPointsFromDurability;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool RandomizeAmmo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FMinMaxInt RandomAmmo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FGameplayTag AmmoType;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool ChangeLootPointsFromAmmo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FGameplayTag> ConfigTags;
    FPRLootEntryConfig();
};
