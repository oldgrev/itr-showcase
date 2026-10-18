#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "VRControllerComponent.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UVRControllerComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UVRControllerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateControllerMesh(USceneComponent* Parent);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetMeshVisibility(bool Visible);

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    void IsMeshVisibile(bool& Visible);

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    void GetMaterial(UMaterialInstanceDynamic*& Material);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLeft;
};
