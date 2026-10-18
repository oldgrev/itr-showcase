#include "FLAnimation.h"

UFLAnimation::UFLAnimation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UFLAnimation::GetDurationOfActiveNotifyState(const UAnimInstance* AnimInstance, const UAnimNotifyState* AnimNotifyStateInstance, float& OutDuration) {
    return {};
}

float UFLAnimation::GetAnimSequencePlayLength(const UAnimSequenceBase* Anim, const float StartTime, const bool bPlayingBackwards) {
    return {};
}

