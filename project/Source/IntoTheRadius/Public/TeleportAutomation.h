#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RadiusAutomationBase.h"
#include "TeleportAutomation.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UTeleportAutomation : public URadiusAutomationBase {
    GENERATED_BODY()
public:
    UTeleportAutomation(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void LevelReadyCallback();

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float TeleportDelayInSec;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 MaxLevelPosition;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FGameplayTag> LevelList;
private:
    UPROPERTY()
    TArray<AActor*> LevelPositionList;
};
