#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition.h"
#include "PRCondition_ItemsList.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_ItemsList : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_ItemsList(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> ItemConfigIDsList;
};
