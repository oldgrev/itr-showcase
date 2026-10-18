#pragma once

#include "CoreMinimal.h"
#include "FingerCurls.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FFingerCurls {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Thumb;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Index;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Middle;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Ring;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Pinky;
    FFingerCurls();
};
