#include "FLItems.h"

UFLItems::UFLItems(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UFLItems::OilVerticesAtLocation(UStaticMeshComponent* StaticMeshComponent, FVector WorldLocation, float DrawSize) {
}

void UFLItems::LightDetection(const USpotLightComponent* Spot) {
}

bool UFLItems::IsWeaponItem(const UInventoryItem* Item) {
    return {};
}

bool UFLItems::IsSimpleItem(const UInventoryItem* Item) {
    return {};
}

bool UFLItems::IsItemActorCanBeTraded(AActor* itemActor) {
    return {};
}

bool UFLItems::IsAmmoItem(const UInventoryItem* Item) {
    return {};
}

bool UFLItems::IsAmmoContainerItem(const UInventoryItem* Item) {
    return {};
}

int32 UFLItems::GetTotalPrice(TArray<AActor*> Actors, const bool bIsSelling) {
    return {};
}

void UFLItems::GetStatReliability(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood) {
}

void UFLItems::GetStatRecoil(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood) {
}

void UFLItems::GetStatRatios(UInventoryItem* Item, const EWeaponInfoParameter Parameter, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood) {
}

void UFLItems::GetStatFireRate(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood) {
}

void UFLItems::GetStatDamage(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood) {
}

void UFLItems::GetStatAccuracy(UInventoryItem* Item, float& White, float& Red, float& Green, int32& PercentChange, bool& bGood) {
}

int32 UFLItems::GetSellPrice(AActor* itemActor, bool bIgnoreIfAttached, bool bItemOnly) {
    return {};
}

int32 UFLItems::GetRepairTime(const AActor* itemActor, bool ignoreIfAttached) {
    return {};
}

int32 UFLItems::GetRepairPrice(const AActor* itemActor, bool ignoreIfAttached) {
    return {};
}

void UFLItems::GetItemClass(const UInventoryItem* Item, TSubclassOf<AActor>& itemClass) {
}

void UFLItems::GetCleanableMeshes(AActor* Actor, UMaterial* ComparisonMaterial, TArray<UStaticMeshComponent*>& outMeshes, int32& outCleanbleVertices) {
}

FText UFLItems::GetActorAssociatedName(AActor* Actor) {
    return {};
}

UPRItemConfig* UFLItems::CreateConfig(FGameplayTag ItemTag, const FString& UID) {
    return {};
}

TArray<UInventoryItem*> UFLItems::ConstructItemFromConfig(UPRItemConfig* Config) {
    return {};
}

UInventoryItem* UFLItems::ConstructDefaultItem(const FGameplayTag Tag, const FString CustomUID, TArray<FGameplayTag> AdditionalTags, const FGameplayTag HolderID, const float DurabilityRatio) {
    return {};
}

UInventoryItem* UFLItems::ConstructActorItem(AActor* Actor, const FString& CustomUID, TArray<FGameplayTag> AdditionalTags, float DurabilityRatio) {
    return {};
}

UInventoryItem* UFLItems::CloneInventoryItem(UInventoryItem* Item, const FString& CustomID) {
    return {};
}

int32 UFLItems::CleanVerticesAtLocation(UStaticMeshComponent* StaticMeshComponent, FVector WorldLocation, float DrawSize) {
    return {};
}

void UFLItems::CalculateSmoothingAlpha(bool& bOutIsAligned, float& OutAlignAlpha, UCameraComponent* VRCameraRef, UMeshComponent* Mesh, const FName SocketName, const float DistanceLimit, const float AlphaThreshold) {
}

