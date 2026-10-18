#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MinimapCliffMappingConfig.h"
#include "MinimapFoliageMappingConfig.h"
#include "MinimapMeshMappingConfig.h"
#include "MinimapConfig.generated.h"

class UDataTable;
class UStaticMesh;
class UTexture2D;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMinimapConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UMinimapConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<UTexture2D*, FMinimapMeshMappingConfig> iconMapping;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<UTexture2D*, FMinimapMeshMappingConfig> landscapeMapping;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<UTexture2D*, FMinimapFoliageMappingConfig> foliageMapping;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<UStaticMesh*, FMinimapCliffMappingConfig> cliffMapping;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, FColor> forestTypeMapping;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<UDataTable*> forestInfoTables;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float treeRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float waterScanStep;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float waterRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float waterMinDeph;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MapImageOversize;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MapImageSize;
};
