#pragma once

#include "CoreMinimal.h"
#include "EPRPlatformType.h"
#include "PoolActorConfig.generated.h"

class AActor;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPoolActorConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> ActorClass;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<EPRPlatformType> PlatformTypes;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 InitCount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxCount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool ReCreateOnDestroy;
    FPoolActorConfig();
    ~FPoolActorConfig();
};
