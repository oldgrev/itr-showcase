#pragma once

#include "CoreMinimal.h"
#include "ActorSpawnInfo.h"
#include "ItemSpawnInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FItemSpawnInfo : public FActorSpawnInfo {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FString SpawnerId;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float LootPossibilityOverride;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool ProjectOnGround;
    FItemSpawnInfo();
    ~FItemSpawnInfo();
};
