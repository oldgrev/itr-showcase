#pragma once

#include "CoreMinimal.h"
#include "Component_And_Transform.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FComponent_And_Transform {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Transform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UPrimitiveComponent* PrimitiveComponent;
    FComponent_And_Transform();
};
