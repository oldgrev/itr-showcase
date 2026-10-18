#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "GameEnvironment.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API AGameEnvironment : public APRBasicActor {
    GENERATED_BODY()
public:
    AGameEnvironment(const FObjectInitializer& ObjectInitializer);

};
