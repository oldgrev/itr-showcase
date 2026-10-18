#pragma once

#include "CoreMinimal.h"
#include "PRModificator.generated.h"

class UPRCondition;

UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class INTOTHERADIUS_API UPRModificator : public UObject {
    GENERATED_BODY()
public:
    UPRModificator(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced)
    UPRCondition* Condition;
};
