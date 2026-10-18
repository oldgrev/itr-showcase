#pragma once

#include "CoreMinimal.h"
#include "ItemConfigsList.h"
#include "SpawnGameData.h"
#include "StashData.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FStashData : public FSpawnGameData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FItemConfigsList ItemConfigs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool UseCustomConfigs;
    FStashData();
};
