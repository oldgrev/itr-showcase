#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "RadiusAutomationComponent.generated.h"

class URadiusAutomationBase;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API URadiusAutomationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    URadiusAutomationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void MainMenuReadyCallback(FGameplayTag LevelTag);

    UFUNCTION()
    void GameStartedCallback();

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<TSubclassOf<URadiusAutomationBase>> AutomationList;
private:
    UPROPERTY()
    URadiusAutomationBase* ActiveAutomation;
};
