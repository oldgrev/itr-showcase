#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Bot_StopAttackCpp.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UBTT_Bot_StopAttackCpp : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTT_Bot_StopAttackCpp(const FObjectInitializer& ObjectInitializer);

};
