#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ActorActivationVolumeManager.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UActorActivationVolumeManager : public UObject {
    GENERATED_BODY()
public:
    UActorActivationVolumeManager(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void OnTransitionStart();

    UFUNCTION()
    void OnLevelPrepare(FGameplayTag LevelTag);

};
