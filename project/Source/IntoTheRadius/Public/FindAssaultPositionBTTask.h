#pragma once

#include "CoreMinimal.h"
#include "CoverBTTask.h"
#include "FindAssaultPositionBTTask.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFindAssaultPositionBTTask : public UCoverBTTask {
    GENERATED_BODY()
public:
    UFindAssaultPositionBTTask(const FObjectInitializer& ObjectInitializer);

};
