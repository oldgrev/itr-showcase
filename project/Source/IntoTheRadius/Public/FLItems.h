#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EWeaponInfoParameter.h"
#include "FLItems.generated.h"

class AActor;
class UCameraComponent;
class UInventoryItem;
class UMaterial;
class UMeshComponent;
class UPRItemConfig;
class USpotLightComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLItems : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLItems(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void OilVerticesAtLocation(UStaticMeshComponent* StaticMeshComponent, FVector WorldLocation, float DrawSize);

    UFUNCTION(BlueprintCallable)
    static void LightDetection(const USpotLightComponent* Spot);

    UFUNCTION(BlueprintPure)
    static bool IsWeaponItem(const UInventoryItem* Item);

    UFUNCTION(BlueprintPure)
    static bool IsSimpleItem(const UInventoryItem* Item);

    UFUNCTION(BlueprintPure)
    static bool IsItemActorCanBeTraded(AActor* itemActor);

    UFUNCTION(BlueprintPure)
    static bool IsAmmoItem(const UInventoryItem* Item);

    UFUNCTION(BlueprintPure)
    static bool IsAmmoContainerItem(const UInventoryItem* Item);

    UFUNCTION(BlueprintPure)
    static int32 GetTotalPrice(TArray<AActor*> Actors, const bool bIsSelling);

    UFUNCTION(BlueprintPure)
    static void GetStatReliability(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood);

    UFUNCTION(BlueprintPure)
    static void GetStatRecoil(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood);

    UFUNCTION(BlueprintPure)
    static void GetStatRatios(UInventoryItem* Item, const EWeaponInfoParameter Parameter, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood);

    UFUNCTION(BlueprintPure)
    static void GetStatFireRate(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood);

    UFUNCTION(BlueprintPure)
    static void GetStatDamage(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood);

    UFUNCTION(BlueprintPure)
    static void GetStatAccuracy(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood);

    UFUNCTION(BlueprintPure)
    static int32 GetSellPrice(AActor* itemActor, bool bIgnoreIfAttached, bool bItemOnly);

    UFUNCTION(BlueprintPure)
    static int32 GetRepairTime(const AActor* itemActor, bool ignoreIfAttached);

    UFUNCTION(BlueprintPure)
    static int32 GetRepairPrice(const AActor* itemActor, bool ignoreIfAttached);

    UFUNCTION(BlueprintPure)
    static void GetItemClass(const UInventoryItem* Item, TSubclassOf<AActor>& itemClass);

    UFUNCTION(BlueprintCallable)
    static void GetCleanableMeshes(AActor* Actor, UMaterial* ComparisonMaterial, TArray<UStaticMeshComponent*>& outMeshes, int32& outCleanbleVertices);

    UFUNCTION(BlueprintPure)
    static FText GetActorAssociatedName(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    static UPRItemConfig* CreateConfig(FGameplayTag ItemTag, const FString& UID);

    UFUNCTION(BlueprintCallable)
    static TArray<UInventoryItem*> ConstructItemFromConfig(UPRItemConfig* Config);

    UFUNCTION(BlueprintPure)
    static UInventoryItem* ConstructDefaultItem(const FGameplayTag Tag, const FString CustomUID, TArray<FGameplayTag> AdditionalTags, const FGameplayTag HolderID, const float DurabilityRatio);

    UFUNCTION(BlueprintPure)
    static UInventoryItem* ConstructActorItem(AActor* Actor, const FString& CustomUID, TArray<FGameplayTag> AdditionalTags, float DurabilityRatio);

    UFUNCTION(BlueprintCallable)
    static UInventoryItem* CloneInventoryItem(UInventoryItem* Item, const FString& CustomID);

    UFUNCTION(BlueprintCallable)
    static int32 CleanVerticesAtLocation(UStaticMeshComponent* StaticMeshComponent, FVector WorldLocation, float DrawSize);

    UFUNCTION(BlueprintCallable)
    static void CalculateSmoothingAlpha(bool& bOutIsAligned, float& OutAlignAlpha, UCameraComponent* VRCameraRef, UMeshComponent* Mesh, const FName SocketName, const float DistanceLimit, const float AlphaThreshold);

};
