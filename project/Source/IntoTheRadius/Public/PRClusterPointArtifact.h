#pragma once

#include "CoreMinimal.h"
#include "PRBasicSceneComponent.h"
#include "PRClusterPointArtifact.generated.h"

class UBillboardComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPRClusterPointArtifact : public UPRBasicSceneComponent {
    GENERATED_BODY()
public:
    UPRClusterPointArtifact(const FObjectInitializer& ObjectInitializer);

private:
    UPROPERTY()
    UBillboardComponent* Billboard;
};
