#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "IAsset.h"
#include "AmmoConfig.generated.h"

class AActor;
class UAmmoConfig;
class UDataTable;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UAmmoConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    UAmmoConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void SetupAmmoMeshComponent(const FGameplayTag& AmmoTag, UStaticMeshComponent* AmmoMeshComponent, const bool IsFired);

    UFUNCTION(BlueprintPure)
    static bool IsTakenOutAmmo(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    bool IsShrapnelAmmo(FGameplayTag AmmoTag);

    UFUNCTION(BlueprintPure)
    static bool IsHeldAmmo(AActor* Actor);

    UFUNCTION(BlueprintPure)
    static bool IsAmmo(const AActor* Actor);

    UFUNCTION(BlueprintPure)
    static UStaticMesh* GetAmmoWholeMesh(const FGameplayTag& AmmoType);

    UFUNCTION(BlueprintPure)
    static FText GetAmmoTypeName(const FGameplayTag& AmmoType);

    UFUNCTION(BlueprintPure)
    static FLinearColor GetAmmoTypeColor(const FGameplayTag& AmmoType);

    UFUNCTION(BlueprintPure)
    static UAmmoConfig* GetAmmoTagsConfig();

    UFUNCTION(BlueprintPure)
    static UStaticMesh* GetAmmoShellMesh(const FGameplayTag& AmmoType);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* CommonInfoTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MeshPrimitiveDataIndex;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ProjectileForwardSpawnOffset;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> BulletClassActor;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> GrenadeClassActor;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> ShrapnelClassActor;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> ShrapnelTags;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> ExplosionClassActor;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector2D AirExplosionShrapnelAccuracyRange;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector2D AirExplosionBulletAccuracyRange;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector ExplosionProjectilesOriginOffset;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector ExplosionProjectilesBoxExtend;
};
