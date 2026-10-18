#pragma once

#include "CoreMinimal.h"
#include "PRModificator_Int.h"
#include "PRModificator_Int_PercentsAdd.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Int_PercentsAdd : public UPRModificator_Int {
    GENERATED_BODY()
public:
    UPRModificator_Int_PercentsAdd(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float PercentsAdd;
};
