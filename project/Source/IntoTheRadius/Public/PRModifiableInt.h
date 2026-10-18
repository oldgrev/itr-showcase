#pragma once

#include "CoreMinimal.h"
#include "PRModifiableInt.generated.h"

class UPRModificator_Int;

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class INTOTHERADIUS_API UPRModifiableInt : public UObject {
    GENERATED_BODY()
public:
    UPRModifiableInt(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 Value;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced)
    TArray<UPRModificator_Int*> Modificators;
};
