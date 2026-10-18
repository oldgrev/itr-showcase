#pragma once

#include "CoreMinimal.h"
#include "IAttachment.generated.h"

class UAttachmentSlotComponent;

UINTERFACE(MinimalAPI, Blueprintable)
class UIAttachment : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIAttachment {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsAttached();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void DetachFrom(UAttachmentSlotComponent* SlotComponent);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void AttachTo(UAttachmentSlotComponent* SlotComponent, const bool bMakeSound);

};
