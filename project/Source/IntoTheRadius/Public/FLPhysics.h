#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLPhysics.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLPhysics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLPhysics(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static UPrimitiveComponent* ToggleSimulatePhysics(const AActor* Actor, const bool bState);

};
