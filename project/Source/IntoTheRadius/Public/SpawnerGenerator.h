#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IInstanceID.h"
#include "PRBasicActor.h"
#include "SpawnerGenerator.generated.h"

class AActor;
class AMonsterSpawner;
class ASpawnerGeneratorAlternativePlace;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API ASpawnerGenerator : public APRBasicActor, public IIInstanceID {
    GENERATED_BODY()
public:
    ASpawnerGenerator(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void StopGenerator();

public:
    UFUNCTION(BlueprintCallable)
    bool Special() const;

protected:
    UFUNCTION(BlueprintCallable)
    void SaveGeneratorData();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnSpawnerReadyToCall(AMonsterSpawner* Spawner);

    UFUNCTION(BlueprintCallable)
    void CallSpawner(AMonsterSpawner* Spawner, bool& bSuccess, AActor*& NPCActor);

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag generatorID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<AMonsterSpawner*> Spawners;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CooldownSeconds;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HitPoints;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ForceSpecial;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<ASpawnerGeneratorAlternativePlace*> AlternativePlaces;
};
