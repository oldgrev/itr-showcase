#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IAsset.h"
#include "PoolActorConfig.h"
#include "PoolManagerConfig.generated.h"

class UPoolManagerConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPoolManagerConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    UPoolManagerConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static UPoolManagerConfig* GetPoolManagerConfig();

private:
    UPROPERTY(EditAnywhere)
    TArray<FPoolActorConfig> ActorConfigs;
};
