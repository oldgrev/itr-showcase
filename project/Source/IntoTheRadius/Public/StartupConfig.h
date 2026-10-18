#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StartupConfig.generated.h"

class UPRItemConfig;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FStartupConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 Money;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRItemConfig*> Items;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> Triggers;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> OpenedLevels;
    FStartupConfig();
    ~FStartupConfig();
};
