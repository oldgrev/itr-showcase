#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "ShopBin.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API AShopBin : public APRBasicActor {
    GENERATED_BODY()
public:
    AShopBin(const FObjectInitializer& ObjectInitializer);

};
