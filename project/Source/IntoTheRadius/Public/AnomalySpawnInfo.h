#pragma once

#include "CoreMinimal.h"
#include "ActorSpawnInfo.h"
#include "AnomalySpawnInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FAnomalySpawnInfo : public FActorSpawnInfo {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FString CustomID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FString Name;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float Radius;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool ProjectOnGround;
    FAnomalySpawnInfo();
    ~FAnomalySpawnInfo();
};
