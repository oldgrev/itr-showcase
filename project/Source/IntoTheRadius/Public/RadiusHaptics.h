#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EHapticsType.h"
#include "RadiusHaptics.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusHaptics : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    EHapticsType Type;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FString> FeedbackId;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float Intensity;
    FRadiusHaptics();
};
