#pragma once

#include "CoreMinimal.h"
#include "MinMaxFloat.h"
#include "RecoilParameters.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRecoilParameters {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 OverallRecoilInfoPercent;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat VerticalRecoil;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat HorizontalRecoil;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FVector RecoilLocationOffset;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat StabilizedVerticalRecoil;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat StabilizedHorizontalRecoil;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FVector StabilizedRecoilLocationOffset;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float RecoilAutoFireCoefficient;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float RecoilLocationAutoFireCoefficient;
    FRecoilParameters();
};
