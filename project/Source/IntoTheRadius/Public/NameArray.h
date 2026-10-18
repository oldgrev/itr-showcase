#pragma once

#include "CoreMinimal.h"
#include "NameArray.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FNameArray {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> Names;
    FNameArray();
    ~FNameArray();
};
