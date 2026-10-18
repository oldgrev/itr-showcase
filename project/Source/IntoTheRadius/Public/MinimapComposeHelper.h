#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MinimapComposeHelper.generated.h"

class AInstancedFoliageActor;
class ALandscape;
class UFoliageType;
class UInstancedStaticMeshComponent;
class ULandscapeSplinesComponent;
class UObject;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMinimapComposeHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMinimapComposeHelper(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void PrepareLandscape(ALandscape* Landscape);

    UFUNCTION(BlueprintCallable)
    static TArray<FIntVector> GetPointsFromFile(const FString FilePath);

    UFUNCTION(BlueprintCallable)
    static TArray<FVector> GetLocations(UInstancedStaticMeshComponent* Component);

    UFUNCTION(BlueprintCallable)
    static ULandscapeSplinesComponent* GetLandscapeSplines(const ALandscape* Landscape);

    UFUNCTION(BlueprintCallable)
    static void GetHeatmapFromFile(const FString FilePath, const int32 step, TMap<FIntPoint, int32>& heatmap, FIntPoint& Min, FIntPoint& Max, int32& MaxValue);

    UFUNCTION(BlueprintCallable)
    static TArray<FTransform> GetFoliageTransforms(AInstancedFoliageActor* foliageActor, UFoliageType* FoliageType);

    UFUNCTION(BlueprintCallable)
    static void GenerateHeatmapFromFile(UObject* WorldContextObject, const FString FilePath, const int32 step);

};
