#pragma once

#include "CoreMinimal.h"
#include "PRCondition.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class INTOTHERADIUS_API UPRCondition : public UObject {
    GENERATED_BODY()
public:
    UPRCondition(const FObjectInitializer& ObjectInitializer);

};
