#include "MapPointsConfig.h"
#include "ITRDefaults.h"

UMapPointsConfig::UMapPointsConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.MapPointsConfig"));
}

FTransform UMapPointsConfig::WorldToLevelTransform(FGameplayTag LevelTag, FTransform Transform) {
    return {};
}

FVector UMapPointsConfig::WorldToLevelLocation(FGameplayTag LevelTag, FVector Location) {
    return {};
}

void UMapPointsConfig::ResolvePoint(FGameplayTag pointTag, TArray<FGameplayTag> ExcludedPoints, FGameplayTag& ResultPoint, FGameplayTag& ResultLevel) {
}

FTransform UMapPointsConfig::LevelToWorldTransform(FGameplayTag LevelTag, FTransform Transform) {
    return {};
}

FVector UMapPointsConfig::LevelToWorldLocation(FGameplayTag LevelTag, FVector Location) {
    return {};
}

bool UMapPointsConfig::IsPointInLevel(FGameplayTag pointTag, FGameplayTag LevelTag) {
    return {};
}

bool UMapPointsConfig::IsPointACluster(FGameplayTag pointTag) {
    return {};
}

void UMapPointsConfig::GetPointTransforms(FGameplayTag pointTag, bool& bSuccess, FGameplayTag& LevelTag, FTransform& RelativeTransform, FTransform& absoluteTransform) {
}

FGameplayTag UMapPointsConfig::GetPointLevel(FGameplayTag pointTag) const {
    return {};
}

UMapPointsConfig* UMapPointsConfig::GetMapPointsConfig() {
    return {};
}

TArray<FGateInfo> UMapPointsConfig::GetLevelGateInfos(const FGameplayTag LevelTag) {
    return {};
}

