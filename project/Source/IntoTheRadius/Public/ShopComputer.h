#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "ShopComputer.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API AShopComputer : public APRBasicActor {
    GENERATED_BODY()
public:
    AShopComputer(const FObjectInitializer& ObjectInitializer);

};
