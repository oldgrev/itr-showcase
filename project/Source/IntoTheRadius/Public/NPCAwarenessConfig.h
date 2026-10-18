#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "NPCAwarenessConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCAwarenessConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AwarenessLowLevel;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AwarenessHighLevel;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AwarenessDecrease;
    FNPCAwarenessConfig();
    ~FNPCAwarenessConfig();
};
