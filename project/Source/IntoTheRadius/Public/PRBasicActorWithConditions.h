#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "PRBasicActorWithConditions.generated.h"

class UPRCondition;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRBasicActorWithConditions : public APRBasicActor {
    GENERATED_BODY()
public:
    APRBasicActorWithConditions(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    bool CheckActorConditions();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
};
