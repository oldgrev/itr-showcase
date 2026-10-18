#pragma once

#include "CoreMinimal.h"
#include "LevelDecorData.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FLevelDecorData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FString, FTransform> ItemTransforms;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FString> DestroyedItems;
    FLevelDecorData();
    ~FLevelDecorData();
};
