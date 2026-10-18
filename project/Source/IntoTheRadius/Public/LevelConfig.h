#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MinMaxInt.h"
#include "LevelConfig.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FLevelConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag LevelTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText LevelName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName MainSublevel;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FName> StaticSublevels;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bTutorialLevel;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool StopGameTimeTick;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool ReloadOnTideHappening;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool InventoryAllowed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool SleepAllowed;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FMinMaxInt AllowedGenerators;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool SaveOnExit;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool Autosave;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool SaveOnLoad;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UMaterialInterface* MapMaterial;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UMaterialInterface* MapLegendMaterial;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MapScale;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MapRotation;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxLevelRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool FullPlayerStats;
    FLevelConfig();
    ~FLevelConfig();
};
