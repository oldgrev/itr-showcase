#pragma once

#include "CoreMinimal.h"
#include "PRModificator_Float.h"
#include "PRModificator_Float_Percentage.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Float_Percentage : public UPRModificator_Float {
    GENERATED_BODY()
public:
    UPRModificator_Float_Percentage(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Percentage;
};
