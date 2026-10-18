#pragma once

#include "CoreMinimal.h"
#include "EJournalGroup.h"
#include "RecordSubtitle.h"
#include "Record.generated.h"

class USoundBase;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FRecord {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EJournalGroup Group;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Name;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText JournalText;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    USoundBase* Sound;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FRecordSubtitle> Subtitles;
    FRecord();
    ~FRecord();
};
