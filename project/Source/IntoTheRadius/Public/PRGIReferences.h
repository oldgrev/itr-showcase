#pragma once

#include "CoreMinimal.h"
#include "PRGIStarter.h"
#include "PRGIReferences.generated.h"

class UInterface;
class UObject;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRGIReferences : public UPRGIStarter {
    GENERATED_BODY()
public:
    UPRGIReferences(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static UObject* GetControllerReference(const TSubclassOf<UInterface> Interface);

private:
    UPROPERTY()
    TMap<TSubclassOf<UInterface>, UObject*> Controllers;
};
