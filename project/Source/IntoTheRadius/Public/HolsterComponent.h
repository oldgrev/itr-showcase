#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "EInventoryMode.h"
#include "IItemHolder.h"
#include "HolsterComponent.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UHolsterComponent : public USceneComponent, public IIItemHolder {
    GENERATED_BODY()
public:
    UHolsterComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void CheckInteractionMode(const EInventoryMode Mode, bool& allow) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void CalcDistance(AActor* targetActor, bool& bInRange, float& Distance);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void AttachAndLerpHold();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag ID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* Holds;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WorkDistance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 InventoryModes;
};
