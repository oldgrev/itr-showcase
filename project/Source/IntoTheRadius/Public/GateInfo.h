#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GateInfo.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FGateInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag LeadsFrom;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag LeadsTo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag UnlockTrigger;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector LocationInLevel;
    FGateInfo();
};
