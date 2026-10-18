#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ELevelManagerState.h"
#include "IClearable.h"
#include "IPreparable.h"
#include "LevelManager.generated.h"

class ULevelManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ULevelManager : public UObject, public IIPreparable, public IIClearable {
    GENERATED_BODY()
public:
    ULevelManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnloadSublevel(const FName& SublevelName);

    UFUNCTION(BlueprintCallable)
    void UnloadLevel(const FGameplayTag LevelTag);

    UFUNCTION(BlueprintCallable)
    void UnloadAll();

    UFUNCTION(BlueprintCallable)
    void ShowSublevel(const FName& SublevelName);

private:
    UFUNCTION()
    void OnUnloadingTick();

    UFUNCTION()
    void OnLoadingTick();

public:
    UFUNCTION(BlueprintCallable)
    void LoadSublevel(const FName& SublevelName);

    UFUNCTION(BlueprintCallable)
    void LoadLevel(const FGameplayTag LevelTag);

    UFUNCTION(BlueprintCallable)
    bool IsReady() const;

    UFUNCTION(BlueprintCallable)
    void HideSublevel(const FName& SublevelName, const bool bKeepLoaded);

    UFUNCTION(BlueprintPure)
    static ULevelManager* GetLevelManager();

    UPROPERTY(BlueprintReadOnly)
    ELevelManagerState State;
};
