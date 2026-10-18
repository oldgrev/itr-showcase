#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IInstanceID.h"
#include "NPCGameData.h"
#include "OneParamMonsterSpawnerDelegate.h"
#include "PRBasicActor.h"
#include "MonsterSpawner.generated.h"

class AActor;
class UObject;
class USphereComponent;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API AMonsterSpawner : public APRBasicActor, public IIInstanceID {
    GENERATED_BODY()
public:
    AMonsterSpawner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void ToggleNpcSummary(UObject* WorldContextObj);

    UFUNCTION(BlueprintCallable)
    void SpawnSavedNPC(bool& bSuccess, AActor*& NPCActor);

    UFUNCTION(BlueprintCallable)
    void SpawnNPC(bool& bSuccess, AActor*& NPCActor);

private:
    UFUNCTION()
    void OnNPCDied(AActor* NPCActor);

public:
    UFUNCTION(BlueprintPure)
    static TMap<FGameplayTag, int32> NPCsListToMonstersMap(const TArray<FGameplayTag>& List);

    UFUNCTION(BlueprintPure)
    static bool IsNpcSummaryEnabled();

    UFUNCTION(BlueprintPure)
    bool IsFull();

    UPROPERTY(BlueprintAssignable)
    FOneParamMonsterSpawner OnWildSpawnerCleared;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    USphereComponent* Sphere;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool Wild;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(ExposeOnSpawn=true))
    FString SpawnerInstanceID;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(ExposeOnSpawn=true))
    bool bForceInstanceID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    float Radius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    TMap<FGameplayTag, int32> Monsters;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    bool CanWalkAway;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    bool SnipingMode;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    int32 AlternativeMonstersMax;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    FGameplayTag KillMissionPointTag;
private:
    UPROPERTY()
    TArray<FNPCGameData> SavedNPCsToSpawn;
    UPROPERTY()
    TArray<AActor*> NPCActors;
};
