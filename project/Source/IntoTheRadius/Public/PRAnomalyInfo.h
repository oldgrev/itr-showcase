#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "MinMaxFloat.h"
#include "PRAnomalyInfo.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRAnomalyInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag TypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<AActor> ActorClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText Name;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText Description;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat RadiusRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FMinMaxFloat DamageRange;
    FPRAnomalyInfo();
    ~FPRAnomalyInfo();
};
