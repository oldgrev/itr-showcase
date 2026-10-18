#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "CloseCombatManagerTickFunction.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FCloseCombatManagerTickFunction : public FTickFunction {
    GENERATED_BODY()

    FCloseCombatManagerTickFunction();
};

template<>
struct TStructOpsTypeTraits<FCloseCombatManagerTickFunction> : public TStructOpsTypeTraitsBase2<FCloseCombatManagerTickFunction> {
    enum {
        WithCopy = false,
    };
};
