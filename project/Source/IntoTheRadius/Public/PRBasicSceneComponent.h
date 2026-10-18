#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "PRBasicSceneComponent.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRBasicSceneComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPRBasicSceneComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnLevelStarted(FGameplayTag LevelTag);

    UFUNCTION(BlueprintImplementableEvent)
    void OnLevelPrepare(FGameplayTag LevelTag);

private:
    UFUNCTION()
    void OnGameStartedPrivate();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnGameStarted();

};
