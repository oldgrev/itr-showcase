#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionAbstractObjectiveData.h"
#include "MissionInfoObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionInfoObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionInfoObjectiveData(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> Points;
};
