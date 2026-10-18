#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AmmoInfo.h"
#include "PRBasicActorComponent.h"
#include "ShrapnelComponentApplyDamageDelegate.h"
#include "ShrapnelComponentImpactDelegate.h"
#include "RadiusShrapnelComponent.generated.h"

class UDamageType;
class UPhysicalMaterial;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API URadiusShrapnelComponent : public UPRBasicActorComponent {
    GENERATED_BODY()
public:
    URadiusShrapnelComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Initialize(const FAmmoInfo& AmmoInfo, float Damage, float Accuracy, FVector Offset, float TraceDistance);

    UFUNCTION(BlueprintCallable)
    void Execute();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 MaxCount;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FGameplayTag BuckShotTag;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName TraceProfileName;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UDamageType> DamageClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float ParticalScale;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float PenetrationParticalScale;
    UPROPERTY(EditDefaultsOnly)
    UPhysicalMaterial* MetalMaterial;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MaxAccuracySpread;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MinAccuracySpread;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float DistanceStep;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MinTraceDistance;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MaxDamageScale;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MinDamage;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool DestroyAfterExecute;
    UPROPERTY(BlueprintAssignable)
    FShrapnelComponentImpact OnImpact;
    UPROPERTY(BlueprintAssignable)
    FShrapnelComponentApplyDamage OnApplyDamage;
};
