#pragma once

#include "CoreMinimal.h"
#include "PaperNote.h"
#include "ConditionalPaperNote.generated.h"

class UPRCondition;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FConditionalPaperNote : public FPaperNote {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    FConditionalPaperNote();
    ~FConditionalPaperNote();
};
