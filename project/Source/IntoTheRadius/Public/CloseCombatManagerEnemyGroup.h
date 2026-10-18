#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CloseCombatManagerEnemyGroup.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FCloseCombatManagerEnemyGroup {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MinEnemyAllowed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer EnemyGroup;
    FCloseCombatManagerEnemyGroup();
    ~FCloseCombatManagerEnemyGroup();
};
