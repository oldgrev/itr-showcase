#pragma once

#include "CoreMinimal.h"
#include "CoverBTTask.h"
#include "FindShootingPositionBTTask.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFindShootingPositionBTTask : public UCoverBTTask {
    GENERATED_BODY()
public:
    UFindShootingPositionBTTask(const FObjectInitializer& ObjectInitializer);

};
