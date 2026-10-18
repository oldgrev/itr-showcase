#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTD_BlackboardBool.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UBTD_BlackboardBool : public UBTDecorator_BlackboardBase {
    GENERATED_BODY()
public:
    UBTD_BlackboardBool(const FObjectInitializer& ObjectInitializer);

};
