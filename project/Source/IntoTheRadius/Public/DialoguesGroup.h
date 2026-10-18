#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Dialogue.h"
#include "DialoguesGroup.generated.h"

class UPRCondition;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FDialoguesGroup {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag GroupID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FDialogue> Cassettes;
    FDialoguesGroup();
    ~FDialoguesGroup();
};
