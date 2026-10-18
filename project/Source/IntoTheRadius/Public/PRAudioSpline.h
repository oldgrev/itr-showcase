#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "PRAudioSpline.generated.h"

class UAudioComponent;
class USplineComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRAudioSpline : public APRBasicActor {
    GENERATED_BODY()
public:
    APRAudioSpline(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    USplineComponent* Spline;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UAudioComponent* Audio;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float LoopBeginMin;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float LoopBeginMax;
};
