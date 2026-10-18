#pragma once

#include "CoreMinimal.h"
#include "NpcInfo.generated.h"

class ACharacter;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNpcInfo {
    GENERATED_BODY()

    UPROPERTY()
    ACharacter* CharacterRef;
    FNpcInfo();
};
