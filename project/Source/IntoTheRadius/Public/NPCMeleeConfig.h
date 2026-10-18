#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MinMaxFloat.h"
#include "NPCMeleeConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCMeleeConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat DamageRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat DistanceRange;
    FNPCMeleeConfig();
    ~FNPCMeleeConfig();
};
