#pragma once

#include "CoreMinimal.h"
#include "PRCondition_Mission.h"
#include "PRCondition_MissionActive.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_MissionActive : public UPRCondition_Mission {
    GENERATED_BODY()
public:
    UPRCondition_MissionActive(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool InProgress;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool InverseCheck;
};
