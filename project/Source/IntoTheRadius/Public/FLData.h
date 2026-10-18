#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLData : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLData(const FObjectInitializer& ObjectInitializer);

};
