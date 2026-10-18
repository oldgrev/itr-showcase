#pragma once

#include "CoreMinimal.h"
#include "SaveInfo.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FSaveInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SaveNr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool Autosave;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool Ironman;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FDateTime DateTime;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 TimeSpentMinutes;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 Money;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FString SaveMessage;
    FSaveInfo();
    ~FSaveInfo();
};
