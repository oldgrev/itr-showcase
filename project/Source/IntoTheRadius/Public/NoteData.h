#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EJournalGroup.h"
#include "NoteData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FNoteData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EJournalGroup Group;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Title;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Text;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UTexture2D* Image;
    FNoteData();
    ~FNoteData();
};
