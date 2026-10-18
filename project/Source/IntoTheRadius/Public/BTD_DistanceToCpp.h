#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_IsAtLocation.h"
#include "BTD_DistanceToCpp.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UBTD_DistanceToCpp : public UBTDecorator_IsAtLocation {
    GENERATED_BODY()
public:
    UBTD_DistanceToCpp(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere)
    float RefreshInterval;
};
