#pragma once

#include "CoreMinimal.h"
#include "PRBasicActorComponent.h"
#include "TeleportPointInfo.h"
#include "RadiusPlayerMovementComponent.generated.h"

class ACharacter;
class ARadiusTeleportArcController;
class UCapsuleComponent;
class UCharacterMovementComponent;
class UPlayerStatsComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API URadiusPlayerMovementComponent : public UPRBasicActorComponent {
    GENERATED_BODY()
public:
    URadiusPlayerMovementComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopMovement();

    UFUNCTION(BlueprintCallable)
    void ProcessMovementTeleport(const float DeltaSeconds);

    UFUNCTION(BlueprintCallable)
    void ProcessMovementNormal(const float DeltaSeconds);

    UFUNCTION(BlueprintCallable)
    void ProcessMovement(const float DeltaSeconds);

    UFUNCTION(BlueprintCallable)
    TArray<FTeleportPointInfo> PreparePointsToTeleport(const FVector& From, const FVector& To);

    UFUNCTION(BlueprintCallable)
    bool IsTeleporting() const;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<ARadiusTeleportArcController> ArcControllerClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    ARadiusTeleportArcController* ArcController;
private:
    UPROPERTY()
    ACharacter* CharacterOwner;
    UPROPERTY()
    UCapsuleComponent* OwnerCapsule;
    UPROPERTY()
    UCharacterMovementComponent* MovementComponent;
    UPROPERTY()
    UPlayerStatsComponent* StatsComponent;
};
