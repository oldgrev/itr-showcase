#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Bot_StartAttackCpp.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UBTT_Bot_StartAttackCpp : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTT_Bot_StartAttackCpp(const FObjectInitializer& ObjectInitializer);

};
