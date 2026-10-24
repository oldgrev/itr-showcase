#pragma once

#include "CoreMinimal.h"
#include "CoverSettings.h"
#include "PRBasicActor.h"
#include "CoverLoader.generated.h"

class AActor;
class UCoverDebugComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ACoverLoader : public APRBasicActor {
    GENERATED_BODY()
public:
    ACoverLoader(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere)
    FCoverSettings CoverSettings;
    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> ShippingDebugActor;
private:
    UPROPERTY(EditAnywhere)
    UCoverDebugComponent* DebugComponent;
    UPROPERTY(EditAnywhere)
    TArray<FVector> CoverPoints;
    UPROPERTY(EditAnywhere)
    TArray<FVector> ShootingPositions;
};
