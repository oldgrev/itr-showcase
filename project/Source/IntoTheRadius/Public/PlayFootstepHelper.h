#pragma once

#include "CoreMinimal.h"
#include "AITypes.h"
#include "Navigation/PathFollowingComponent.h"
#include "PlayFootstepHelper.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPlayFootstepHelper : public UObject {
    GENERATED_BODY()
public:
    UPlayFootstepHelper(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    void OnMoveStart(FAIRequestID RequestID, TEnumAsByte<EPathFollowingStatus::Type> MovementStatus);

    UFUNCTION()
    void OnMoveEnd(FAIRequestID RequestID, TEnumAsByte<EPathFollowingResult::Type> MovementResult);

};
