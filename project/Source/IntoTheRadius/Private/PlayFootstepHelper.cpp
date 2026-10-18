#include "PlayFootstepHelper.h"

UPlayFootstepHelper::UPlayFootstepHelper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UPlayFootstepHelper::OnMoveStart(FAIRequestID RequestID, TEnumAsByte<EPathFollowingStatus::Type> MovementStatus) {
}

void UPlayFootstepHelper::OnMoveEnd(FAIRequestID RequestID, TEnumAsByte<EPathFollowingResult::Type> MovementResult) {
}

