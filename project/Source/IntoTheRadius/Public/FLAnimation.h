#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLAnimation.generated.h"

class UAnimInstance;
class UAnimNotifyState;
class UAnimSequenceBase;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLAnimation : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLAnimation(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static bool GetDurationOfActiveNotifyState(const UAnimInstance* AnimInstance, const UAnimNotifyState* AnimNotifyStateInstance, float& OutDuration);

    UFUNCTION(BlueprintPure)
    static float GetAnimSequencePlayLength(const UAnimSequenceBase* Anim, const float StartTime, const bool bPlayingBackwards);

};
