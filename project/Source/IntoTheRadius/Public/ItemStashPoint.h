#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "ItemStashPoint.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UItemStashPoint : public USceneComponent, public IGameplayTagAssetInterface {
    GENERATED_BODY()
public:
    UItemStashPoint(const FObjectInitializer& ObjectInitializer);

    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTagContainer GameplayTags;
};
