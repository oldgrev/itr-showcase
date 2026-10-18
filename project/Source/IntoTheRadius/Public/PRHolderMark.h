#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "PRHolderMark.generated.h"

class AActor;
class UHolsterComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRHolderMark : public APRBasicActor {
    GENERATED_BODY()
public:
    APRHolderMark(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void Update();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void LinkActor(AActor* ActorInHand, bool bIsLeft);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void InitHolsterRef(UHolsterComponent* holsterRef);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void Highlight(bool bIsLeft);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetDistances(bool& bLeftInRange, float& leftDistance, bool& bRightInRange, float& rightDistance);

    UFUNCTION(BlueprintCallable)
    const AActor* GetActorInRightHand();

    UFUNCTION(BlueprintCallable)
    const AActor* GetActorInLeftHand();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* ActorInLeftHand;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* ActorInRightHand;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    UHolsterComponent* holsterRef;
};
