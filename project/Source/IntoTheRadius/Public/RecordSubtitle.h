#pragma once

#include "CoreMinimal.h"
#include "EPRSubtitleType.h"
#include "MinMaxFloat.h"
#include "RecordSubtitle.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FRecordSubtitle {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPRSubtitleType Type;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Text;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FMinMaxFloat TimeFromTo;
    FRecordSubtitle();
    ~FRecordSubtitle();
};
