#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemDropInfo.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FItemDropInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag LevelTag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Transform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ItemIdList;
    FItemDropInfo();
    ~FItemDropInfo();
};
