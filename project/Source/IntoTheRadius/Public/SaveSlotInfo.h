#pragma once

#include "CoreMinimal.h"
#include "SaveInfo.h"
#include "SaveSlotInfo.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FSaveSlotInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SlotNr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<int32, FSaveInfo> Saves;
    FSaveSlotInfo();
    ~FSaveSlotInfo();
};
