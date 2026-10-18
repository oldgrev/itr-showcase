#pragma once

#include "CoreMinimal.h"
#include "ItemConfigsList.generated.h"

class UPRItemConfig;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FItemConfigsList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    TArray<UPRItemConfig*> Configs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomUID;
    FItemConfigsList();
    ~FItemConfigsList();
};
