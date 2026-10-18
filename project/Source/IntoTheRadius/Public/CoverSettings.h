#pragma once

#include "CoreMinimal.h"
#include "CoverSettings.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FCoverSettings {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    float CoverPointMinDistance;
    UPROPERTY(EditAnywhere)
    float SmallestAgentHeight;
    UPROPERTY(EditAnywhere)
    float CoverPointGroundOffset;
    UPROPERTY(EditAnywhere)
    float DistanceToCoverObject;
    UPROPERTY(EditAnywhere)
    float ShootingPositionOffset;
    UPROPERTY(EditAnywhere)
    float MinCoverWidth;
    UPROPERTY(EditAnywhere)
    float OpenPointsGridCellSize;
    UPROPERTY(EditAnywhere)
    bool bAddCoversToFreePoints;
    FCoverSettings();
};
