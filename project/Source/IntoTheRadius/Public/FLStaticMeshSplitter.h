#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLStaticMeshSplitter.generated.h"

class AActor;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLStaticMeshSplitter : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLStaticMeshSplitter(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    static TArray<AActor*> SplitStaticMeshByMaterial(AActor* inputActor);

    UFUNCTION(BlueprintCallable)
    static void SetLodScreenSize(UStaticMeshComponent* StaticMeshComponent, int32 LODIndex, float ScreenSize);

    UFUNCTION(BlueprintCallable)
    static void SetLightMapResolution(UStaticMeshComponent* StaticMeshComponent, int32 Resolution);

    UFUNCTION(BlueprintCallable)
    static void SetLightmapCoordinateIndex(UStaticMesh* StaticMesh, int32 coordinateIndex);

    UFUNCTION(BlueprintCallable)
    static bool SetCustomDataInTexcoord(UStaticMeshComponent* StaticMeshComponent, int32 textureCoordIndex, FVector2D customData);

    UFUNCTION(BlueprintCallable)
    static void RemoveCollisionFromLodSections(UStaticMeshComponent* StaticMeshComponent);

    UFUNCTION(BlueprintCallable)
    static FVector2D PackTintAndTextureIndex(FLinearColor Tint, int32 TextureIndex);

    UFUNCTION(BlueprintCallable)
    static void CreateEmptyLod(UStaticMeshComponent* StaticMeshComponent);

    UFUNCTION(BlueprintCallable)
    static void CreateCopyOfExistingLod(UStaticMeshComponent* StaticMeshComponent, int32 sourceLodIndex);

    UFUNCTION(BlueprintCallable)
    static void BuildStaticMesh(UStaticMesh* StaticMesh);

};
