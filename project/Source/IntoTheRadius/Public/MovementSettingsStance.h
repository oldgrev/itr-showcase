#pragma once

#include "CoreMinimal.h"
#include "MovementSettings.h"
#include "MovementSettingsStance.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FMovementSettingsStance {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMovementSettings Standing;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMovementSettings Crouching;
    FMovementSettingsStance();
};
