#include "PlayerConfig.h"
#include "ITRDefaults.h"

UPlayerConfig::UPlayerConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.PlayerConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("StartMaxPlayerHP"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("HealthBoothPriceHealth"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("HealthBoothPriceRest"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("SleepHealthIncreaseSpeed"), (double)0.00231481483);
    ITRDefaults::Set(GetClass(), this, TEXT("StartWalkSpeed"), (double)220);
    ITRDefaults::Set(GetClass(), this, TEXT("StartSprintSpeed"), (double)750);
    ITRDefaults::Set(GetClass(), this, TEXT("StartCrouchSpeed"), (double)90);
    ITRDefaults::Set(GetClass(), this, TEXT("WaterMovementReductionCurve.EditorCurveData.DefaultValue"), (double)3.40282347e+38);
    ITRDefaults::Set(GetClass(), this, TEXT("WaterMovementReductionCurve.EditorCurveData.PreInfinityExtrap"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("WaterMovementReductionCurve.EditorCurveData.PostInfinityExtrap"), (double)4);
    ITRDefaults::SetNum(GetClass(), this, TEXT("WaterMovementReductionCurve.EditorCurveData.Keys"), 0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("WaterMovementReductionCurve.ExternalCurve"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportTraceDownDistance"), (double)2000);
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportSpeed"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportMaxStepHeight"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportStaminaUsePerMeterFromDistanceMetersCurve.EditorCurveData.DefaultValue"), (double)3.40282347e+38);
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportStaminaUsePerMeterFromDistanceMetersCurve.EditorCurveData.PreInfinityExtrap"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportStaminaUsePerMeterFromDistanceMetersCurve.EditorCurveData.PostInfinityExtrap"), (double)4);
    ITRDefaults::SetNum(GetClass(), this, TEXT("TeleportStaminaUsePerMeterFromDistanceMetersCurve.EditorCurveData.Keys"), 0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("TeleportStaminaUsePerMeterFromDistanceMetersCurve.ExternalCurve"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportAnomaliesTimerDivisor"), (double)5);
    ITRDefaults::Set(GetClass(), this, TEXT("PoisonedWaterDot"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("WaterDrowningDot"), (double)25);
    ITRDefaults::Set(GetClass(), this, TEXT("WaterStaminaDot"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("SpeedToFallDamageCurve.EditorCurveData.DefaultValue"), (double)3.40282347e+38);
    ITRDefaults::Set(GetClass(), this, TEXT("SpeedToFallDamageCurve.EditorCurveData.PreInfinityExtrap"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("SpeedToFallDamageCurve.EditorCurveData.PostInfinityExtrap"), (double)4);
    ITRDefaults::SetNum(GetClass(), this, TEXT("SpeedToFallDamageCurve.EditorCurveData.Keys"), 0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("SpeedToFallDamageCurve.ExternalCurve"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxPlayerStamina"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("StartSprintStaminaUsage"), (double)0.216666669);
    ITRDefaults::Set(GetClass(), this, TEXT("StaminaUsageCoefficient"), (double)0.00900000054);
    ITRDefaults::Set(GetClass(), this, TEXT("StaminaRegenerationSpeed"), (double)0.0666666701);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxPlayerRest"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("StartRestIncreaseSpeed"), (double)0.00166666671);
    ITRDefaults::Set(GetClass(), this, TEXT("StartRestDecreaseSpeed"), (double)0.000833333354);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxPlayerNutrition"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxPlayerHunger"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("HungerSpeed"), (double)0.000833333354);
    ITRDefaults::Set(GetClass(), this, TEXT("HungerTolerance"), (double)40);
    ITRDefaults::Set(GetClass(), this, TEXT("ShortForwardGripRadius"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripDeadZone"), (double)35);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripSphereTraceRadius"), (double)60);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripTraceLength"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("LoadAmmoContainersIfInHands"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("LoadAmmoBoxesIfNotInHands"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("DeathItemsDropRadius"), (double)300);
    ITRDefaults::Set(GetClass(), this, TEXT("InventoryItemsPositionTreshold"), (double)1500);
    ITRDefaults::Set(GetClass(), this, TEXT("SystemSubtitlesType"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("CameraSubtitlesType"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowDelay"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectHideDelay"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowDistance"), (double)40);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowMinAngles.X"), (double)-0.300000012);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowMinAngles.Y"), (double)-0.600000024);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowMinAngles.Z"), (double)-0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowMaxAngles.X"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowMaxAngles.Y"), (double)0.300000012);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectShowMaxAngles.Z"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectHideMinAngles.X"), (double)-0.600000024);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectHideMinAngles.Y"), (double)-1.20000005);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectHideMinAngles.Z"), (double)-1);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectHideMaxAngles.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectHideMaxAngles.Y"), (double)0.600000024);
    ITRDefaults::Set(GetClass(), this, TEXT("InspectHideMaxAngles.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToWalkSpeedPercent.EditorCurveData.DefaultValue"), (double)3.40282347e+38);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToWalkSpeedPercent.EditorCurveData.PreInfinityExtrap"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToWalkSpeedPercent.EditorCurveData.PostInfinityExtrap"), (double)4);
    ITRDefaults::SetNum(GetClass(), this, TEXT("WeightToWalkSpeedPercent.EditorCurveData.Keys"), 0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("WeightToWalkSpeedPercent.ExternalCurve"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToRunSpeedPercent.EditorCurveData.DefaultValue"), (double)3.40282347e+38);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToRunSpeedPercent.EditorCurveData.PreInfinityExtrap"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToRunSpeedPercent.EditorCurveData.PostInfinityExtrap"), (double)4);
    ITRDefaults::SetNum(GetClass(), this, TEXT("WeightToRunSpeedPercent.EditorCurveData.Keys"), 0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("WeightToRunSpeedPercent.ExternalCurve"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToStaminaPercent.EditorCurveData.DefaultValue"), (double)3.40282347e+38);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToStaminaPercent.EditorCurveData.PreInfinityExtrap"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("WeightToStaminaPercent.EditorCurveData.PostInfinityExtrap"), (double)4);
    ITRDefaults::SetNum(GetClass(), this, TEXT("WeightToStaminaPercent.EditorCurveData.Keys"), 0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("WeightToStaminaPercent.ExternalCurve"), nullptr);
}

void UPlayerConfig::GetWeightToWarningColor(const float Weight, FLinearColor& Color) {
}

void UPlayerConfig::GetWeightToWalkSpeedCoefficient(const float Weight, float& SpeedCoefficient) {
}

void UPlayerConfig::GetWeightToStaminaCoefficient(const float Weight, float& Coefficient) {
}

void UPlayerConfig::GetWeightToRunSpeedCoefficient(const float Weight, float& SpeedCoefficient) {
}

void UPlayerConfig::GetWaterMovementReductionCoefficient(float BodyInWaterRatio, float& MovementCoefficient) {
}

float UPlayerConfig::GetStaminaRegenerationSpeed() const {
    return {};
}

UPlayerConfig* UPlayerConfig::GetPlayerConfig() {
    return {};
}

void UPlayerConfig::GetFallDamage(float SpeedDelta, float& Damage) {
}

