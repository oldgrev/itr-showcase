#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "PRClusterPattern.generated.h"

class USceneComponent;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRClusterPattern : public APRBasicActor {
    GENERATED_BODY()
public:
    APRClusterPattern(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    USceneComponent* Root;
};
