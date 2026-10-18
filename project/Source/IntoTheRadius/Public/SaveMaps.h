#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SaveMaps.generated.h"

class UTextureRenderTarget2D;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FSaveMaps {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SlotNr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SaveNr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, UTextureRenderTarget2D*> RenderTargets;
    FSaveMaps();
};
