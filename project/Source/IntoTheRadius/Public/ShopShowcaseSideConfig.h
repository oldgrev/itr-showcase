#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ShopShowcaseSideConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FShopShowcaseSideConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Name;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> Items;
    FShopShowcaseSideConfig();
    ~FShopShowcaseSideConfig();
};
