#pragma once

#include "CoreMinimal.h"
#include "GrippableStaticMeshComponent.h"
#include "PRGrippableStaticMeshComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPRGrippableStaticMeshComponent : public UGrippableStaticMeshComponent {
    GENERATED_BODY()
public:
    UPRGrippableStaticMeshComponent(const FObjectInitializer& ObjectInitializer);

};
