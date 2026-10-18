#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EMapMarker.h"
#include "PRBasicActor.h"
#include "PRMapMarker.generated.h"

class UPRCondition;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRMapMarker : public APRBasicActor {
    GENERATED_BODY()
public:
    APRMapMarker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    bool IsConditionsPassed();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag MarkerID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EMapMarker MarkerType;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
};
