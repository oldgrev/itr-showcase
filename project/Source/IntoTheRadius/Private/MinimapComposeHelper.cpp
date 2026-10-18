#include "MinimapComposeHelper.h"

UMinimapComposeHelper::UMinimapComposeHelper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UMinimapComposeHelper::PrepareLandscape(ALandscape* Landscape) {
}

TArray<FIntVector> UMinimapComposeHelper::GetPointsFromFile(const FString FilePath) {
    return {};
}

TArray<FVector> UMinimapComposeHelper::GetLocations(UInstancedStaticMeshComponent* Component) {
    return {};
}

ULandscapeSplinesComponent* UMinimapComposeHelper::GetLandscapeSplines(const ALandscape* Landscape) {
    return {};
}

void UMinimapComposeHelper::GetHeatmapFromFile(const FString FilePath, const int32 step, TMap<FIntPoint, int32>& heatmap, FIntPoint& Min, FIntPoint& Max, int32& MaxValue) {
}

TArray<FTransform> UMinimapComposeHelper::GetFoliageTransforms(AInstancedFoliageActor* foliageActor, UFoliageType* FoliageType) {
    return {};
}

void UMinimapComposeHelper::GenerateHeatmapFromFile(UObject* WorldContextObject, const FString FilePath, const int32 step) {
}

