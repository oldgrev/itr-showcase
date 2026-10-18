#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IInstanceID.h"
#include "ILootSpawner.h"
#include "PRBasicActor.h"
#include "PRLootSpawner.generated.h"

class UPRItemConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRLootSpawner : public APRBasicActor, public IIInstanceID, public IILootSpawner {
    GENERATED_BODY()
public:
    APRLootSpawner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    void OnCheckDistanceTick();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    FString InstanceId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InstanceIdPrefix;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool TryProject;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ExcludeNonFit;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    int32 LootPoints;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    FGameplayTag LootTable;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, meta=(ExposeOnSpawn=true))
    TArray<UPRItemConfig*> CustomLootConfigs;
};
