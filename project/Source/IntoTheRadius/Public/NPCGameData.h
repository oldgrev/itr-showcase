#pragma once

#include "CoreMinimal.h"
#include "SpawnGameData.h"
#include "NPCGameData.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNPCGameData : public FSpawnGameData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Health;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Awareness;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector POI;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    uint8 Command;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bHasAmmo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLowAmmo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsEnemySpotted;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bHasKnownEnemyLoc;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bHasSquad;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSnipingMode;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsQuest;
    FNPCGameData();
    ~FNPCGameData();
};
