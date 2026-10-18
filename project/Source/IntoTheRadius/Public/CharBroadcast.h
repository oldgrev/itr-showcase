#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActor.h"
#include "CharBroadcast.generated.h"

class AActor;
class ACharBroadcast;
class UObject;
class USphereComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ACharBroadcast : public APRBasicActor {
    GENERATED_BODY()
public:
    ACharBroadcast(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static ACharBroadcast* SpawnBroadcast(UObject* WorldContext, FTransform SpawnTransform, FGameplayTag MissionKillPointTag, float LifeSpan, float SphereRadius);

    UFUNCTION(BlueprintCallable)
    void AlertOthers(AActor* Caller, AActor*& Target, FTransform Location);

private:
    UPROPERTY()
    USphereComponent* Sphere;
public:
    UPROPERTY(BlueprintReadWrite)
    float Radius;
    UPROPERTY(BlueprintReadWrite)
    float LifeTime;
    UPROPERTY(BlueprintReadWrite)
    FGameplayTag MissionKillPoint;
};
