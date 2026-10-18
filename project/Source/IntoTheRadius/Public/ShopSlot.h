#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActor.h"
#include "ShopSlot.generated.h"

class AActor;
class USceneComponent;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API AShopSlot : public APRBasicActor {
    GENERATED_BODY()
public:
    AShopSlot(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void UpdateSlot(USceneComponent* componentToReturnActorTo, const FGameplayTag& GameplayTag, AActor* actorToAttach);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetLock(bool bLock, bool bAnnounce);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Clear();

};
