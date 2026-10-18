#pragma once

#include "CoreMinimal.h"
#include "ActorsArray.h"
#include "IClearable.h"
#include "PoolManager.generated.h"

class AActor;
class APawn;
class UPoolManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPoolManager : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UPoolManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool ReturnActor(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    void PrefillPoolFromConfig();

    UFUNCTION(BlueprintPure)
    bool IsActorInPool(const AActor* Actor);

    UFUNCTION(BlueprintPure)
    static UPoolManager* GetPoolManager();

    UFUNCTION(BlueprintCallable)
    AActor* GetActor(const TSubclassOf<AActor> ActorClass, const FTransform Transform, AActor* Owner, APawn* Instigator);

private:
    UPROPERTY()
    TMap<TSubclassOf<AActor>, FActorsArray> Pool;
};
