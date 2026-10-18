#pragma once

#include "CoreMinimal.h"
#include "EPRSubtitleType.h"
#include "DialogueLine.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FDialogueLine {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPRSubtitleType Type;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Text;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TimeNoAudio;
    FDialogueLine();
    ~FDialogueLine();
};
