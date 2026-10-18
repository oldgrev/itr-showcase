#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "TeleportPointInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FTeleportPointInfo {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FVector Location;
    UPROPERTY(BlueprintReadOnly)
    FHitResult HitResult;
    FTeleportPointInfo();
};
