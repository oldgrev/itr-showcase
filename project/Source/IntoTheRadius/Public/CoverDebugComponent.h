#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CoverDebugComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UCoverDebugComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UCoverDebugComponent(const FObjectInitializer& ObjectInitializer);

private:
    UPROPERTY(EditAnywhere)
    bool bDebugDrawCoverPoints;
    UPROPERTY(EditAnywhere)
    bool bDebugDrawShootingPositions;
};
