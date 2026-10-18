#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "StaticMeshDataForInstanced.h"
#include "StaticMeshDataForInstancedCollection.h"
#include "PRGenerateInstancedStaticMeshVolume.generated.h"

class AActor;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRGenerateInstancedStaticMeshVolume : public APhysicsVolume {
    GENERATED_BODY()
public:
    APRGenerateInstancedStaticMeshVolume(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ShowHiddenStaticMeshComponents();

    UFUNCTION(BlueprintCallable)
    void ShowAllGeneratedInstanced();

    UFUNCTION(BlueprintCallable)
    void RestoreHidden();

    UFUNCTION(BlueprintCallable)
    void RehideHiddenStaticMeshComponents();

    UFUNCTION(BlueprintCallable)
    void HideAllGeneratedInstanced();

    UFUNCTION(BlueprintCallable)
    void GatherMulitipleSmActors();

    UFUNCTION(BlueprintCallable)
    void DestroyAllGeneratedInstanced();

    UFUNCTION(BlueprintCallable)
    void CreateMultipleInstanced();

    UFUNCTION(BlueprintCallable)
    void CreateInstanced();

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UStaticMesh> StaticMeshToSearch;
    UPROPERTY(EditAnywhere)
    FStaticMeshDataForInstanced StaticMeshDataForCreatingInstanced;
    UPROPERTY(EditAnywhere)
    bool bClearVarsAfterEvent;
    UPROPERTY(EditAnywhere)
    TArray<FString> ExcludedStaticMeshList;
    UPROPERTY(EditAnywhere)
    bool bUseMeshDefaultMaterial;
    UPROPERTY(EditAnywhere)
    bool bHideDuplicated;
    UPROPERTY(EditAnywhere)
    bool bCreateHism;
    UPROPERTY(EditAnywhere)
    uint8 MinSmCountToCreateInstanced;
    UPROPERTY(EditDefaultsOnly)
    TSoftClassPtr<AActor> TemplateInstancedActor;
    UPROPERTY(VisibleAnywhere)
    TMap<TSoftObjectPtr<UStaticMesh>, FStaticMeshDataForInstancedCollection> GatheredStaticMeshDataMap;
    UPROPERTY(VisibleAnywhere)
    TArray<TSoftObjectPtr<UStaticMeshComponent>> StaticMeshComponentsHidden;
    UPROPERTY(VisibleAnywhere)
    TArray<TSoftObjectPtr<AActor>> InstancedStaticMeshActorsGenerated;
};
