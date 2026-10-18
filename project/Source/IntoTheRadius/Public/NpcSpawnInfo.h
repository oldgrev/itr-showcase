#pragma once

#include "CoreMinimal.h"
#include "ActorSpawnInfo.h"
#include "NpcSpawnInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNpcSpawnInfo : public FActorSpawnInfo {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FString CustomID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FString SpawnerId;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float LootPossibilityOverride;
    FNpcSpawnInfo();
    ~FNpcSpawnInfo();
};
