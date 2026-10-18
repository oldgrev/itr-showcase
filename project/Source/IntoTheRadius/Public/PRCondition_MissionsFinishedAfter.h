#pragma once

#include "CoreMinimal.h"
#include "MinMaxInt.h"
#include "PRCondition_Mission.h"
#include "PRCondition_MissionsFinishedAfter.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_MissionsFinishedAfter : public UPRCondition_Mission {
    GENERATED_BODY()
public:
    UPRCondition_MissionsFinishedAfter(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool OnlySuccessful;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FMinMaxInt Amount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool InverseCheck;
};
