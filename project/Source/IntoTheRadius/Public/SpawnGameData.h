#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SpawnGameData.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FSpawnGameData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InstanceId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag TypeID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Transform;
    FSpawnGameData();
    ~FSpawnGameData();
};
