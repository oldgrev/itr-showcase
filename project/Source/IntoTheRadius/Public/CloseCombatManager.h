#pragma once

#include "CoreMinimal.h"
#include "ENpcCombatState.h"
#include "IClearable.h"
#include "NpcInfo.h"
#include "CloseCombatManager.generated.h"

class ACharacter;
class APRPlayerCharacter;
class UCloseCombatManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UCloseCombatManager : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UCloseCombatManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnregisterNpc(ACharacter* NpcToUnregister);

    UFUNCTION(BlueprintCallable)
    void ToggleDebug();

    UFUNCTION(BlueprintCallable)
    void RegisterNpc(ACharacter* NpcToRegister);

private:
    UFUNCTION()
    void InitData();

public:
    UFUNCTION(BlueprintCallable)
    float GetTeleportSearchRadius() const;

    UFUNCTION(BlueprintCallable)
    float GetMinDistanceFromPlayerToReappear() const;

    UFUNCTION(BlueprintCallable)
    bool GetDebugEnabled() const;

    UFUNCTION(BlueprintCallable)
    ENpcCombatState GetCloseCombatState(ACharacter* NPC) const;

    UFUNCTION(BlueprintPure)
    static UCloseCombatManager* GetCloseCombatManager();

    UFUNCTION(BlueprintCallable)
    void DebugSetBudget(const float NewBudget);

    UFUNCTION(BlueprintCallable)
    void DebugGetBudget(float& CCBudget, float& Weight);

private:
    UFUNCTION()
    void CleanData();

    UPROPERTY()
    TArray<FNpcInfo> ManagedNpcList;
    UPROPERTY()
    APRPlayerCharacter* PlayerRef;
};
