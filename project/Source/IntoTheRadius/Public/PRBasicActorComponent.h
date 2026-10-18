#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "PRBasicActorComponent.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRBasicActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPRBasicActorComponent(const FObjectInitializer& ObjectInitializer);

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
