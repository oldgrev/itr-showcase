#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "NpcPointQueryManagerTickFunction.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNpcPointQueryManagerTickFunction : public FTickFunction {
    GENERATED_BODY()

    FNpcPointQueryManagerTickFunction();
};

template<>
struct TStructOpsTypeTraits<FNpcPointQueryManagerTickFunction> : public TStructOpsTypeTraitsBase2<FNpcPointQueryManagerTickFunction> {
    enum {
        WithCopy = false,
    };
};
