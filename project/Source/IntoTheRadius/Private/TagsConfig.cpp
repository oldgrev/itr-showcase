#include "TagsConfig.h"
#include "ITRDefaults.h"

UTagsConfig::UTagsConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.TagsConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkStashOpened.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkArtifactVisible.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkFireModeSemi.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkFireModeAuto.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkFireModeBurst3.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkAttachmentOn.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkPocketFlashlightRed.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkNeedToExtractRound.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkBoltOpen.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMarkCigaretteLighting.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagAllStashes.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagStashSmall.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagStashLarge.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagStashHidden.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagAllUpgrades.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItems.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllBoxes.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllMags.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllScopes.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllSilencers.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllCassettes.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllArtifacts.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllCores.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllAmmo.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllWeapons.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllPrimary.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllSecondary.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemAllMap.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagCassettesLore.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemMap.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemCamera.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagItemBackpack.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagHolderHeadDown.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagHolderBackpack.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagHolderHand.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagHolderLeftHand.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagHolderRightHand.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagLevelTransition.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagLevelMainMenu.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagLevelHub.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagLocationTutorialExit.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagLevelStartTutorial.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagLevelShootingRange.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerTutorialSkipped.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerOldTutorialFinished.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerKatyaShown.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerComputerUnlocked.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerTutorialComputerUnlocked.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerTutorialHub.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerTutorialHubEntrance.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagTriggerFreeGame.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMissionsCategories.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMissionsCategoryTutorial.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMissionsCategoryStory.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMissionsCategoryGeneric.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMissionsCategorySpecialArtifacts.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMissionsCategorySpecialGenerators.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagFirstMission.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNPCs.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNPCMimic.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNPCArmoredMimic.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGenerators.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagAnomalies.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagClusters.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagBigClusters.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagMapPoints.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagDefaultSkin.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagCamoSkin.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagDefaultAmmoType.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNoDistanceGrip.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGripTrigger.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGripTriggerIndex.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGripTriggerBoltAndSlide.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGripPriority.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGripPriorityNegative.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGripPriorityOne.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagGripPriorityTwo.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNoiseFootsteps.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNoiseImpact.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNoiseBulletHit.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNoiseWeaponClick.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNoiseWeaponShot.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TagNoiseWeaponExplosion.TagName"), TEXT("None"));
}

UTagsConfig* UTagsConfig::GetTagsConfig() {
    return {};
}

