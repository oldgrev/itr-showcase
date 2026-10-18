#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActor.h"
#include "PRMapCenter.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRMapCenter : public APRBasicActor {
    GENERATED_BODY()
public:
    APRMapCenter(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag LevelTag;
};
