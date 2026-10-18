#pragma once

#include "CoreMinimal.h"
#include "PRModificator_Float.h"
#include "PRModificator_Float_Multiply.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Float_Multiply : public UPRModificator_Float {
    GENERATED_BODY()
public:
    UPRModificator_Float_Multiply(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MultiplyBy;
};
