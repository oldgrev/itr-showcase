#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MovementSettingsStance.h"
#include "MovementSettingsState.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FMovementSettingsState : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMovementSettingsStance VelocityDirection;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMovementSettingsStance LookingDirection;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMovementSettingsStance Aiming;
    FMovementSettingsState();
    ~FMovementSettingsState();
};
