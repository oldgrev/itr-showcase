#pragma once

#include "CoreMinimal.h"
#include "IPhysicsActor.generated.h"

class UPrimitiveComponent;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPhysicsActor : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPhysicsActor {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UPrimitiveComponent* GetPhysicsRootComponent() const;

};
