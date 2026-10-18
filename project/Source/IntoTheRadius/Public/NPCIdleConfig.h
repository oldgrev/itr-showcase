#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MinMaxFloat.h"
#include "NPCAwarenessConfig.h"
#include "NPCIdleConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCIdleConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat WalkSpeedRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat IdleTimeRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat RotationSpeedRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool LookAroundAfterWalk;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCAwarenessConfig AwarenessConfig;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FNPCAwarenessConfig ReducedAwarenessConfig;
    FNPCIdleConfig();
    ~FNPCIdleConfig();
};
