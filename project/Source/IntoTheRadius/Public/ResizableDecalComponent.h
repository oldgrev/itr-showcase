#pragma once

#include "CoreMinimal.h"
#include "Components/DecalComponent.h"
#include "ResizableDecalComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UResizableDecalComponent : public UDecalComponent {
    GENERATED_BODY()
public:
    UResizableDecalComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetDecalSize(FVector newSize);

};
