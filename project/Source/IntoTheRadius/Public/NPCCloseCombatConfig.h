#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "NPCCloseCombatConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCCloseCombatConfig : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool UseCloseCombatManager;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float CloseCombatWeight;
    FNPCCloseCombatConfig();
    ~FNPCCloseCombatConfig();
};
