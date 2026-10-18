#pragma once

#include "CoreMinimal.h"
#include "PRHandPoseInfo.h"
#include "IHandPoser.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIHandPoser : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIHandPoser {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetPoseConfig(FPRHandPoseInfo& Info);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetItemShift(FTransform& Shift);

};
