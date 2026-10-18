#pragma once

#include "CoreMinimal.h"
#include "PRModificator_Float.h"
#include "PRModificator_Float_Add.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Float_Add : public UPRModificator_Float {
    GENERATED_BODY()
public:
    UPRModificator_Float_Add(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Add;
};
