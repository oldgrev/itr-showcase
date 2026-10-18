#pragma once

#include "CoreMinimal.h"
#include "FollowPlayerData.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FFollowPlayerData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    bool bFollowPlayer;
    UPROPERTY(EditAnywhere)
    float PlayerFollowVelocityModifier;
    UPROPERTY(EditAnywhere)
    FVector PlayerFollowOffset;
    FFollowPlayerData();
};
