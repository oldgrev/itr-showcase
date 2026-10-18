#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActor.h"
#include "PRMapPoint.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRMapPoint : public APRBasicActor {
    GENERATED_BODY()
public:
    APRMapPoint(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag pointTag;
};
