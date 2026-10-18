#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "PRPointOfInterest.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRPointOfInterest : public APRBasicActor {
    GENERATED_BODY()
public:
    APRPointOfInterest(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPoiValid;
};
