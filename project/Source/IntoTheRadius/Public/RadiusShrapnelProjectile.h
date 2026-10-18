#pragma once

#include "CoreMinimal.h"
#include "RadiusProjectile.h"
#include "RadiusShrapnelProjectile.generated.h"

class URadiusShrapnelComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusShrapnelProjectile : public ARadiusProjectile {
    GENERATED_BODY()
public:
    ARadiusShrapnelProjectile(const FObjectInitializer& ObjectInitializer);

protected:
    UPROPERTY(VisibleDefaultsOnly)
    URadiusShrapnelComponent* ShrapnelComponent;
};
