#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AmmoInfo.h"
#include "PRAmmoContainerInfo.h"
#include "PRAnomalyInfo.h"
#include "PRHandPoseInfo.h"
#include "PRHandPoseInfosPair.h"
#include "PRItemInfo.h"
#include "PRNPCInfo.h"
#include "TagToTransformsList.h"
#include "WeaponInfo.h"
#include "FLBlutility.generated.h"

class AActor;
class UDataTable;
class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLBlutility : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLBlutility(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static bool SetWeaponInfosToTable(UDataTable* DataTable, TArray<FWeaponInfo> infos);

    UFUNCTION(BlueprintCallable)
    static bool SetPoseInfosToTable(UDataTable* DataTable, TArray<FPRHandPoseInfosPair> Poses);

    UFUNCTION(BlueprintCallable)
    static bool SetNPCInfosToTable(UDataTable* DataTable, TArray<FPRNPCInfo> infos);

    UFUNCTION(BlueprintCallable)
    static bool SetMobility(AActor* Actor, const TEnumAsByte<EComponentMobility::Type> Mobility);

    UFUNCTION(BlueprintCallable)
    static bool SetItemInfosToTable(UDataTable* DataTable, TArray<FPRItemInfo> infos);

    UFUNCTION(BlueprintCallable)
    static bool SetAnomalyInfosToTable(UDataTable* DataTable, TArray<FPRAnomalyInfo> infos);

    UFUNCTION(BlueprintCallable)
    static bool SetAmmoInfosToTable(UDataTable* DataTable, TArray<FAmmoInfo> infos);

    UFUNCTION(BlueprintCallable)
    static bool SetAmmoContainerInfosToTable(UDataTable* DataTable, TArray<FPRAmmoContainerInfo> infos);

    UFUNCTION(BlueprintCallable)
    static bool SetAllowCullDistanceVolume(UStaticMeshComponent* Component, bool bValue);

    UFUNCTION(BlueprintCallable)
    static void SaveDataTable(UDataTable* DataTable);

    UFUNCTION(BlueprintCallable)
    static void ReloadConfigAssets();

    UFUNCTION(BlueprintCallable)
    static void LoadItemInfos(TArray<FPRItemInfo>& Array, bool updateTable);

    UFUNCTION(BlueprintPure)
    static bool CompareHandPoses(FPRHandPoseInfo poseA, FPRHandPoseInfo poseB);

    UFUNCTION(BlueprintCallable)
    static void ClearDataTable(UDataTable* DataTable);

    UFUNCTION(BlueprintCallable)
    static bool AddWeaponInfoToTable(UDataTable* DataTable, FWeaponInfo Info);

    UFUNCTION(BlueprintCallable)
    static bool AddPoseInfoToTable(UDataTable* DataTable, FPRHandPoseInfosPair Pose);

    UFUNCTION(BlueprintCallable)
    static TMap<FGameplayTag, FTagToTransformsList> AddPointData(TMap<FGameplayTag, FTagToTransformsList> In, FGameplayTag LevelTag, FGameplayTag pointTag, FTransform absoluteTransform, TMap<FGameplayTag, FTransform> levelCenters, bool Message, bool duplicateCheck);

    UFUNCTION(BlueprintCallable)
    static bool AddNPCInfoToTable(UDataTable* DataTable, FPRNPCInfo Info);

    UFUNCTION(BlueprintCallable)
    static bool AddItemInfoToTable(UDataTable* DataTable, FPRItemInfo Info);

    UFUNCTION(BlueprintCallable)
    static bool AddAnomalyInfoToTable(UDataTable* DataTable, FPRAnomalyInfo Info);

    UFUNCTION(BlueprintCallable)
    static bool AddAmmoInfoToTable(UDataTable* DataTable, FAmmoInfo Info);

    UFUNCTION(BlueprintCallable)
    static bool AddAmmoContainerInfoToTable(UDataTable* DataTable, FPRAmmoContainerInfo Info);

};
