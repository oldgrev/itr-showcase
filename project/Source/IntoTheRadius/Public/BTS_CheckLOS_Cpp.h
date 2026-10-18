#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_CheckLOS_Cpp.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UBTS_CheckLOS_Cpp : public UBTService_BlackboardBase {
    GENERATED_BODY()
public:
    UBTS_CheckLOS_Cpp(const FObjectInitializer& ObjectInitializer);

};
