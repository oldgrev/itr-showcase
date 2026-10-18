#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_UpdateTargetLocation.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UBTS_UpdateTargetLocation : public UBTService_BlackboardBase {
    GENERATED_BODY()
public:
    UBTS_UpdateTargetLocation(const FObjectInitializer& ObjectInitializer);

};
