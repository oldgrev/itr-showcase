#pragma once

#include "CoreMinimal.h"
#include "EJournalGroup.h"
#include "HostileDescription.generated.h"

class UTexture2D;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FHostileDescription {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EJournalGroup Group;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Title;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UTexture2D* Image;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText JournalText;
    FHostileDescription();
    ~FHostileDescription();
};
