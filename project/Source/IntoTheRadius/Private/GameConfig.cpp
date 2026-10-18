#include "GameConfig.h"
#include "ITRDefaults.h"

UGameConfig::UGameConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.GameConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("LootSpawnDistance"), (double)10000);
    ITRDefaults::Set(GetClass(), this, TEXT("DisableInputInTransitionMonologue"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("LoadingHintsChangeTime"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("LoadingHintsPSOUpdateTime"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("MissionAbortCooldownSeconds"), (double)3600);
    ITRDefaults::Set(GetClass(), this, TEXT("BulletsTag"), TEXT("Bullet"));
    ITRDefaults::Set(GetClass(), this, TEXT("RealMinutesInGameHour"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("TidePeriodInGameHours"), (double)96);
    ITRDefaults::Set(GetClass(), this, TEXT("TideSignalInGameSeconds"), (double)600);
    ITRDefaults::Set(GetClass(), this, TEXT("FogReEnterGameHoursSkip"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("OnlyBigClustersAreSpecial"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("SpecialClusterArtifactTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("SpecialGeneratorShardTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("OrdinaryGeneratorShardTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("AutosaveTimeRealSeconds"), (double)60);
    ITRDefaults::Set(GetClass(), this, TEXT("AutosaveOnIronmanDeath"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("AutosaveIconShownSeconds"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("MinimumPlayerLevelToSkipTutorials"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCAwarenessValues.NoiseFootsteps"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCAwarenessValues.NoiseWeaponSounds"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCAwarenessValues.NoiseWeaponShot"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCAwarenessValues.DamageMultiplier"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("ActivationDistanceToPlayer"), (double)25000);
    ITRDefaults::Set(GetClass(), this, TEXT("CriticalDamageMultiplier"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("CloseCombatConfig.bEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("CloseCombatConfig.CloseRangeRadius"), (double)2000);
    ITRDefaults::Set(GetClass(), this, TEXT("CloseCombatConfig.CircleOfInterestRadius"), (double)15000);
    ITRDefaults::Set(GetClass(), this, TEXT("CloseCombatConfig.MinDistanceFromPlayerToReappear"), (double)4000);
    ITRDefaults::Set(GetClass(), this, TEXT("CloseCombatConfig.TeleportSearchRadius"), (double)4000);
    ITRDefaults::Set(GetClass(), this, TEXT("CloseCombatConfig.Budget"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("AnomalySpawnMultiplier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("AnomalySpawnBlockCutoffRadiusMultiplier"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("AnomaliesSpawnDistance"), (double)10000);
    ITRDefaults::Set(GetClass(), this, TEXT("SellPricePercent"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("ShopSlotInfoTextColor.R"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ShopSlotInfoTextColor.G"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ShopSlotInfoTextColor.B"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ShopSlotInfoTextColor.A"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("RepairPriceToItemPrice"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("RepairSeconds"), (double)600);
    ITRDefaults::SetNum(GetClass(), this, TEXT("NonRepairableItems.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("NonRepairableItems.ParentTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("RodableItems.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("RodableItems.ParentTags"), 0);
}

UGameConfig* UGameConfig::GetGameConfig() {
    return {};
}

void UGameConfig::ApplyStartupConfig(FStartupConfig Config) {
}

