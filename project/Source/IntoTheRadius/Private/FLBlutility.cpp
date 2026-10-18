#include "FLBlutility.h"

UFLBlutility::UFLBlutility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UFLBlutility::SetWeaponInfosToTable(UDataTable* DataTable, TArray<FWeaponInfo> infos) {
    return {};
}

bool UFLBlutility::SetPoseInfosToTable(UDataTable* DataTable, TArray<FPRHandPoseInfosPair> Poses) {
    return {};
}

bool UFLBlutility::SetNPCInfosToTable(UDataTable* DataTable, TArray<FPRNPCInfo> infos) {
    return {};
}

bool UFLBlutility::SetMobility(AActor* Actor, const TEnumAsByte<EComponentMobility::Type> Mobility) {
    return {};
}

bool UFLBlutility::SetItemInfosToTable(UDataTable* DataTable, TArray<FPRItemInfo> infos) {
    return {};
}

bool UFLBlutility::SetAnomalyInfosToTable(UDataTable* DataTable, TArray<FPRAnomalyInfo> infos) {
    return {};
}

bool UFLBlutility::SetAmmoInfosToTable(UDataTable* DataTable, TArray<FAmmoInfo> infos) {
    return {};
}

bool UFLBlutility::SetAmmoContainerInfosToTable(UDataTable* DataTable, TArray<FPRAmmoContainerInfo> infos) {
    return {};
}

bool UFLBlutility::SetAllowCullDistanceVolume(UStaticMeshComponent* Component, bool bValue) {
    return {};
}

void UFLBlutility::SaveDataTable(UDataTable* DataTable) {
}

void UFLBlutility::ReloadConfigAssets() {
}

void UFLBlutility::LoadItemInfos(TArray<FPRItemInfo>& Array, bool updateTable) {
}

bool UFLBlutility::CompareHandPoses(FPRHandPoseInfo poseA, FPRHandPoseInfo poseB) {
    return {};
}

void UFLBlutility::ClearDataTable(UDataTable* DataTable) {
}

bool UFLBlutility::AddWeaponInfoToTable(UDataTable* DataTable, FWeaponInfo Info) {
    return {};
}

bool UFLBlutility::AddPoseInfoToTable(UDataTable* DataTable, FPRHandPoseInfosPair Pose) {
    return {};
}

TMap<FGameplayTag, FTagToTransformsList> UFLBlutility::AddPointData(TMap<FGameplayTag, FTagToTransformsList> In, FGameplayTag LevelTag, FGameplayTag pointTag, FTransform absoluteTransform, TMap<FGameplayTag, FTransform> levelCenters, bool Message, bool duplicateCheck) {
    return {};
}

bool UFLBlutility::AddNPCInfoToTable(UDataTable* DataTable, FPRNPCInfo Info) {
    return {};
}

bool UFLBlutility::AddItemInfoToTable(UDataTable* DataTable, FPRItemInfo Info) {
    return {};
}

bool UFLBlutility::AddAnomalyInfoToTable(UDataTable* DataTable, FPRAnomalyInfo Info) {
    return {};
}

bool UFLBlutility::AddAmmoInfoToTable(UDataTable* DataTable, FAmmoInfo Info) {
    return {};
}

bool UFLBlutility::AddAmmoContainerInfoToTable(UDataTable* DataTable, FPRAmmoContainerInfo Info) {
    return {};
}

