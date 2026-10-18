#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MinMaxFloat.h"
#include "NPCSightConfig.h"
#include "NPCPerceptionConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCPerceptionConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat SenseHearingRadiusRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat SenseNearRadiusRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCSightConfig SenseSightConfig;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat SensesTickTimeRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float SenseSightNightModifier;
    FNPCPerceptionConfig();
    ~FNPCPerceptionConfig();
};
