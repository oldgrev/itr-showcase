#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IInstanceID.h"
#include "MinMaxInt.h"
#include "PRBasicActor.h"
#include "PRClusterSpawner.generated.h"

class APRClusterPattern;
class UPRItemConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRClusterSpawner : public APRBasicActor, public IIInstanceID {
    GENERATED_BODY()
public:
    APRClusterSpawner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    void OnCheckTick();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag ClusterID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<TSubclassOf<APRClusterPattern>> Patterns;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ProjectAnomalies;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> DefaultAtrifacts;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMinMaxInt DefaultAtrifactsCount;
    UPROPERTY(BlueprintReadWrite, Instanced)
    TArray<UPRItemConfig*> MissionAtrifacts;
};
