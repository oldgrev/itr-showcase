#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "RadiusTeleportArcController.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusTeleportArcController : public APRBasicActor {
    GENERATED_BODY()
public:
    ARadiusTeleportArcController(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent)
    void TickArc(const float DeltaSeconds);

};
