#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition.h"
#include "PRCondition_MissionsList.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_MissionsList : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_MissionsList(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> MissionConfigIDsList;
};
