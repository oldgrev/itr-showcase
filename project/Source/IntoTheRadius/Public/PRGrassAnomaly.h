#pragma once

#include "CoreMinimal.h"
#include "PRAnomaly.h"
#include "PlayerLightSensitiveInterface.h"
#include "PRGrassAnomaly.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRGrassAnomaly : public APRAnomaly, public IPlayerLightSensitiveInterface {
    GENERATED_BODY()
public:
    APRGrassAnomaly(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void ReduceComponent(const int32 Index, const float Value);

    UFUNCTION(BlueprintCallable)
    void Initialize();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinScaleValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxScaleValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ShrinkRatio;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float GrowthRatio;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DamageHeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector ComponentParameterBase;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector ComponentParameterRatio;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UStaticMeshComponent*> ComponentsArray;
};
