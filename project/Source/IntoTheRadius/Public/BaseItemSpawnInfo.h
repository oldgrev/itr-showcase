#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ActorSpawnInfo.h"
#include "BaseItemSpawnInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FBaseItemSpawnInfo : public FActorSpawnInfo {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    bool Preconfigured;
    UPROPERTY(BlueprintReadWrite)
    FString CustomUID;
    UPROPERTY(BlueprintReadWrite)
    bool NotUnique;
    UPROPERTY(BlueprintReadWrite)
    TArray<FGameplayTag> CustomAdditionalTags;
    UPROPERTY(BlueprintReadWrite)
    float CustomDurabilityRatio;
    FBaseItemSpawnInfo();
    ~FBaseItemSpawnInfo();
};
