#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "EPRSubtitleType.h"
#include "IAsset.h"
#include "PlayerConfig.generated.h"

class UPlayerConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPlayerConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    UPlayerConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    void GetWeightToWarningColor(const float Weight, FLinearColor& Color);

    UFUNCTION(BlueprintPure)
    void GetWeightToWalkSpeedCoefficient(const float Weight, float& SpeedCoefficient);

    UFUNCTION(BlueprintPure)
    void GetWeightToStaminaCoefficient(const float Weight, float& Coefficient);

    UFUNCTION(BlueprintPure)
    void GetWeightToRunSpeedCoefficient(const float Weight, float& SpeedCoefficient);

    UFUNCTION(BlueprintPure)
    void GetWaterMovementReductionCoefficient(float BodyInWaterRatio, float& MovementCoefficient);

    UFUNCTION(BlueprintCallable)
    float GetStaminaRegenerationSpeed() const;

    UFUNCTION(BlueprintPure)
    static UPlayerConfig* GetPlayerConfig();

    UFUNCTION(BlueprintPure)
    void GetFallDamage(float SpeedDelta, float& Damage);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StartMaxPlayerHP;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 HealthBoothPriceHealth;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 HealthBoothPriceRest;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float SleepHealthIncreaseSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StartWalkSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StartSprintSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StartCrouchSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FRuntimeFloatCurve WaterMovementReductionCurve;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TeleportTraceDownDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool TeleportSweepSteps;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TeleportSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TeleportMaxStepHeight;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FRuntimeFloatCurve TeleportStaminaUsePerMeterFromDistanceMetersCurve;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TeleportAnomaliesTimerDivisor;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float PoisonedWaterDot;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float WaterDrowningDot;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float WaterStaminaDot;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FRuntimeFloatCurve SpeedToFallDamageCurve;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxPlayerStamina;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StartSprintStaminaUsage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StaminaUsageCoefficient;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StaminaRegenerationSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxPlayerRest;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StartRestIncreaseSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float StartRestDecreaseSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxPlayerNutrition;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxPlayerHunger;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float HungerSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float HungerTolerance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> EatableItemTags;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ShortForwardGripRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DistanceGripDeadZone;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DistanceGripSphereTraceRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DistanceGripTraceLength;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool LoadAmmoContainersIfInHands;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool LoadAmmoContainersIfInInventory;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool LoadAmmoBoxesIfNotInHands;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DeathItemsDropRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float InventoryItemsPositionTreshold;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPRSubtitleType SystemSubtitlesType;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPRSubtitleType CameraSubtitlesType;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float InspectShowDelay;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float InspectHideDelay;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float InspectShowDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector InspectShowMinAngles;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector InspectShowMaxAngles;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector InspectHideMinAngles;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector InspectHideMaxAngles;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FRuntimeFloatCurve WeightToWalkSpeedPercent;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FRuntimeFloatCurve WeightToRunSpeedPercent;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FRuntimeFloatCurve WeightToStaminaPercent;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<float, FLinearColor> WeightToWarningColor;
};
