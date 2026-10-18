#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EJournalGroup.h"
#include "PaperNote.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPaperNote {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag NoteID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EJournalGroup Group;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Title;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText PaperText;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText JournalText;
    FPaperNote();
    ~FPaperNote();
};
