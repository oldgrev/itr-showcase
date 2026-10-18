#pragma once

#include "CoreMinimal.h"
#include "PRModificator_Int.h"
#include "PRModificator_Int_Percentage.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Int_Percentage : public UPRModificator_Int {
    GENERATED_BODY()
public:
    UPRModificator_Int_Percentage(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Percentage;
};
