#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameplayTagContainer.h"
#include "EItemSlot.h"
#include "AttachmentSlotComponent.generated.h"

class AActor;
class UBoxComponent;
class UInventoryItem;
class UStaticMesh;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UAttachmentSlotComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UAttachmentSlotComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void TryDetachItem(AActor* Attachment, bool& bSuccess);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void TryAttachItem(AActor* Attachment, bool& bSuccess);

    UFUNCTION(BlueprintCallable)
    void SetSlotEnabled(const bool bEnable);

    UFUNCTION(BlueprintCallable)
    bool IsSlotEnabled() const;

    UFUNCTION(BlueprintCallable)
    bool IsSlotEmpty() const;

    UFUNCTION(BlueprintCallable)
    void IsParentHeld(bool& IsHeld) const;

    UFUNCTION(BlueprintCallable)
    void IsAccepts(const FGameplayTag Type, bool& bCanAttach) const;

    UFUNCTION(BlueprintCallable)
    UInventoryItem* GetParentItem() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EItemSlot Slot;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag AttachmentType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName AttachToSocket;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UStaticMesh* MyStaticMesh;
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxCollision;
};
