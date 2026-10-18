#pragma once

#include "CoreMinimal.h"
#include "PRModificator_Int.h"
#include "PRModificator_Int_Add.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Int_Add : public UPRModificator_Int {
    GENERATED_BODY()
public:
    UPRModificator_Int_Add(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 Add;
};
