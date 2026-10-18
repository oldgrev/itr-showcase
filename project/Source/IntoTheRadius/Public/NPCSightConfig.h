#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MinMaxFloat.h"
#include "NPCSightConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCSightConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat DistanceRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AngleLeft;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AngleRight;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AngleUp;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AngleDown;
    FNPCSightConfig();
    ~FNPCSightConfig();
};
