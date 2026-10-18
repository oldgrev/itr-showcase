#pragma once

#include "CoreMinimal.h"
#include "ActorSpawnInfo.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FActorSpawnInfo {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FTransform Transform;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<AActor> ActorClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool UseRelevanceManager;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    AActor* Owner;
    FActorSpawnInfo();
};
