#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AmmoContainerData.h"
#include "PRItemConfig.generated.h"

class UPRItemConfig;

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class INTOTHERADIUS_API UPRItemConfig : public UObject {
    GENERATED_BODY()
public:
    UPRItemConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    UPRItemConfig* CloneWithUID(const FString& newUID);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag ConfigID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InstanceId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag HolderID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform HolderTransform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Durability;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FAmmoContainerData Ammo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> AdditionalTags;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> Upgrades;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    TArray<UPRItemConfig*> Attachments;
};
