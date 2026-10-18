#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IItemHolder.generated.h"

class AActor;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIItemHolder : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIItemHolder {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SpawnContent();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetHolderVisibility(bool Visible);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetContentVisibility(bool Visible);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void RefreshHolder();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void IsSnapHolder(bool& snapHolder);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void IsAcceptItemActor(AActor* itemActor, bool onlyIfFree, bool& accept);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetHolderID(FGameplayTag& HolderID);

};
