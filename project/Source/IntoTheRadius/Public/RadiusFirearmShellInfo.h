#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RadiusFirearmShellInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusFirearmShellInfo {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FGameplayTag AmmoTag;
    UPROPERTY(BlueprintReadWrite)
    bool IsFired;
    UPROPERTY(BlueprintReadWrite)
    bool IsMetal;
    UPROPERTY(BlueprintReadWrite)
    FVector LinearImpulse;
    UPROPERTY(BlueprintReadWrite)
    FVector AngularImpulse;
    FRadiusFirearmShellInfo();
};
