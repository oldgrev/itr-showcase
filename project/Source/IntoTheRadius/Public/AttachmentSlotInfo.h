#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AttachmentSlotInfo.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FAttachmentSlotInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag TypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UTexture2D* Icon;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText Description;
    FAttachmentSlotInfo();
    ~FAttachmentSlotInfo();
};
