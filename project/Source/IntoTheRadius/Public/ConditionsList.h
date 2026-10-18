#pragma once

#include "CoreMinimal.h"
#include "ConditionsList.generated.h"

class UPRCondition;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FConditionsList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    FConditionsList();
    ~FConditionsList();
};
