#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AmmoCommonInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FAmmoCommonInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag AmmoType;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText Name;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FLinearColor Color;
    FAmmoCommonInfo();
};
