#pragma once

#include "CoreMinimal.h"
#include "RadiusProjectileInfo.h"
#include "RadiusFirearmProjectileInfo.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API URadiusFirearmProjectileInfo : public URadiusProjectileInfo {
    GENERATED_BODY()
public:
    URadiusFirearmProjectileInfo(const FObjectInitializer& ObjectInitializer);

};
