#pragma once

#include "CoreMinimal.h"
#include "RelevanceManager.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API URelevanceManager : public UObject {
    GENERATED_BODY()
public:
    URelevanceManager(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void OnLevelUnloaded();

};
