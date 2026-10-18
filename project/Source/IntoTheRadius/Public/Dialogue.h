#pragma once

#include "CoreMinimal.h"
#include "DialogueLine.h"
#include "EJournalGroup.h"
#include "Dialogue.generated.h"

class UPRCondition;
class USoundBase;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FDialogue {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EJournalGroup Group;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Name;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText JournalText;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    USoundBase* Sound;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FDialogueLine> Lines;
    FDialogue();
    ~FDialogue();
};
