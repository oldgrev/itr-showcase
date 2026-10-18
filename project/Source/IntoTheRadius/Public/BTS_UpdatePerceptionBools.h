#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_UpdatePerceptionBools.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UBTS_UpdatePerceptionBools : public UBTService_BlackboardBase {
    GENERATED_BODY()
public:
    UBTS_UpdatePerceptionBools(const FObjectInitializer& ObjectInitializer);

};
