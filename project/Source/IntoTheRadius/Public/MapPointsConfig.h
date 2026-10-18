#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "GateInfo.h"
#include "IAsset.h"
#include "TagToTransformsList.h"
#include "MapPointsConfig.generated.h"

class UMapPointsConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMapPointsConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    UMapPointsConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    FTransform WorldToLevelTransform(FGameplayTag LevelTag, FTransform Transform);

    UFUNCTION(BlueprintPure)
    FVector WorldToLevelLocation(FGameplayTag LevelTag, FVector Location);

    UFUNCTION(BlueprintPure)
    void ResolvePoint(FGameplayTag pointTag, TArray<FGameplayTag> ExcludedPoints, FGameplayTag& ResultPoint, FGameplayTag& ResultLevel);

    UFUNCTION(BlueprintPure)
    FTransform LevelToWorldTransform(FGameplayTag LevelTag, FTransform Transform);

    UFUNCTION(BlueprintPure)
    FVector LevelToWorldLocation(FGameplayTag LevelTag, FVector Location);

    UFUNCTION(BlueprintPure)
    bool IsPointInLevel(FGameplayTag pointTag, FGameplayTag LevelTag);

    UFUNCTION(BlueprintPure)
    bool IsPointACluster(FGameplayTag pointTag);

    UFUNCTION(BlueprintCallable)
    void GetPointTransforms(FGameplayTag pointTag, bool& bSuccess, FGameplayTag& LevelTag, FTransform& RelativeTransform, FTransform& absoluteTransform);

    UFUNCTION(BlueprintCallable)
    FGameplayTag GetPointLevel(FGameplayTag pointTag) const;

    UFUNCTION(BlueprintPure)
    static UMapPointsConfig* GetMapPointsConfig();

    UFUNCTION(BlueprintPure)
    TArray<FGateInfo> GetLevelGateInfos(const FGameplayTag LevelTag);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FGameplayTag, FTransform> levelCenters;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FGameplayTag, FTagToTransformsList> LevelPoints;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGateInfo> LevelGates;
};
