#pragma once

#include "CoreMinimal.h"
#include "RadiusAutomationBase.h"
#include "ShutdownAutomation.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UShutdownAutomation : public URadiusAutomationBase {
    GENERATED_BODY()
public:
    UShutdownAutomation(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float ShutdownDelayInSec;
};
