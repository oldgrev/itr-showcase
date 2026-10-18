#pragma once

#include "CoreMinimal.h"
#include "PRModificator_Float.h"
#include "PRModificator_Float_PercentsAdd.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Float_PercentsAdd : public UPRModificator_Float {
    GENERATED_BODY()
public:
    UPRModificator_Float_PercentsAdd(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float PercentsAdd;
};
