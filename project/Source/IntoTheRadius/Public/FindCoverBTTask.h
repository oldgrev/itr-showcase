#pragma once

#include "CoreMinimal.h"
#include "CoverBTTask.h"
#include "FindCoverBTTask.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFindCoverBTTask : public UCoverBTTask {
    GENERATED_BODY()
public:
    UFindCoverBTTask(const FObjectInitializer& ObjectInitializer);

};
