#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "ActorActivationVolume.generated.h"

class AActorActivationVolume;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API AActorActivationVolume : public AVolume {
    GENERATED_BODY()
public:
    AActorActivationVolume(const FObjectInitializer& ObjectInitializer);

protected:
    UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
    TArray<AActorActivationVolume*> AdjacentVolumes;
};
