#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition.h"
#include "PRCondition_Item.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_Item : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_Item(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ItemConfigID;
};
