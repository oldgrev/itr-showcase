#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "VRGripInterface.h"
#include "PRVRGripSMComponent.generated.h"

class UGripMotionControllerComponent;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRVRGripSMComponent : public UStaticMeshComponent, public IVRGripInterface {
    GENERATED_BODY()
public:
    UPRVRGripSMComponent(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Stiffness;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damping;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BreakDistance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 GripPriority;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDenyGripping;
    UPROPERTY(BlueprintReadOnly)
    bool _isHeld;
    UPROPERTY(BlueprintReadOnly)
    UGripMotionControllerComponent* HoldingController;
};
