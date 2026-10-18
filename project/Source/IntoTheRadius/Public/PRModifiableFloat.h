#pragma once

#include "CoreMinimal.h"
#include "PRModifiableFloat.generated.h"

class UPRModificator_Float;

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class INTOTHERADIUS_API UPRModifiableFloat : public UObject {
    GENERATED_BODY()
public:
    UPRModifiableFloat(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Value;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced)
    TArray<UPRModificator_Float*> Modificators;
};
