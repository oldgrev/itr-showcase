#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MinMaxFloat.h"
#include "NPCFirearmConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCFirearmConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat DelayRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat FireDeviation;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat ReloadTime;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool InfiniteAmmo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool AllowFriendlyFire;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat AttackLostLocationTime;
    FNPCFirearmConfig();
    ~FNPCFirearmConfig();
};
