#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "RadiusProfilingCamera.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusProfilingCamera : public ACameraActor {
    GENERATED_BODY()
public:
    ARadiusProfilingCamera(const FObjectInitializer& ObjectInitializer);

};
