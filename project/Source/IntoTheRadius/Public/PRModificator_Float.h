#pragma once

#include "CoreMinimal.h"
#include "PRModificator.h"
#include "PRModificator_Float.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Float : public UPRModificator {
    GENERATED_BODY()
public:
    UPRModificator_Float(const FObjectInitializer& ObjectInitializer);

};
