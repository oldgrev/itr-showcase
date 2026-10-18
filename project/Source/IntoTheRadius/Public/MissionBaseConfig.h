#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "MissionBaseConfig.generated.h"

class UPRCondition;
class UPRModifiableFloat;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionBaseConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UMissionBaseConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag ID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText MissionName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText MissionDescription;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    TArray<UPRCondition*> Conditions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    UPRModifiableFloat* WeightOverride;
};
