#pragma once

#include "CoreMinimal.h"
#include "VectorToClass.generated.h"

class AActor;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FVectorToClass {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Vector;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> Class;
    FVectorToClass();
};
