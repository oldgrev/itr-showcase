#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PRSkyBox.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRSkyBox : public AActor {
    GENERATED_BODY()
public:
    APRSkyBox(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    FVector GetRadiusLocation();

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FVector RadiusLocation;
};
