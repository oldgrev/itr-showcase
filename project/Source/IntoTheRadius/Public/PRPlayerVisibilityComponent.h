#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActorComponent.h"
#include "PRPlayerVisibilityComponent.generated.h"

class APREnvironment;
class APRPlayerCharacter;
class UCurveFloat;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPRPlayerVisibilityComponent : public UPRBasicActorComponent {
    GENERATED_BODY()
public:
    UPRPlayerVisibilityComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void InitOnLevelStart(FGameplayTag LevelTag);

protected:
    UFUNCTION(BlueprintCallable)
    void InitOnGameStart();

private:
    UFUNCTION()
    void CleanupOnTransitionStart();

protected:
    UPROPERTY(BlueprintReadOnly)
    APRPlayerCharacter* Player;
    UPROPERTY(BlueprintReadOnly)
    TArray<UPrimitiveComponent*> PlayerPrimitiveList;
    UPROPERTY(BlueprintReadOnly)
    APREnvironment* Environment;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UCurveFloat* DistanceFactorCurve;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UCurveFloat* SunFactorCurve;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UCurveFloat* HeadlampFactorCurve;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UCurveFloat* VelocityFactorCurve;
};
