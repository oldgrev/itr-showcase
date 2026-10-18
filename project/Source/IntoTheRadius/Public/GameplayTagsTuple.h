#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsTuple.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FGameplayTagsTuple {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag First;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Second;
    FGameplayTagsTuple();
};
