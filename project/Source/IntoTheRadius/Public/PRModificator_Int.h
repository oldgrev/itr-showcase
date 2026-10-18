#pragma once

#include "CoreMinimal.h"
#include "PRModificator.h"
#include "PRModificator_Int.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRModificator_Int : public UPRModificator {
    GENERATED_BODY()
public:
    UPRModificator_Int(const FObjectInitializer& ObjectInitializer);

};
