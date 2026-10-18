#include "FLStaticMeshSplitter.h"

UFLStaticMeshSplitter::UFLStaticMeshSplitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

TArray<AActor*> UFLStaticMeshSplitter::SplitStaticMeshByMaterial(AActor* inputActor) {
    return {};
}

void UFLStaticMeshSplitter::SetLodScreenSize(UStaticMeshComponent* StaticMeshComponent, int32 LODIndex, float ScreenSize) {
}

void UFLStaticMeshSplitter::SetLightMapResolution(UStaticMeshComponent* StaticMeshComponent, int32 Resolution) {
}

void UFLStaticMeshSplitter::SetLightmapCoordinateIndex(UStaticMesh* StaticMesh, int32 coordinateIndex) {
}

bool UFLStaticMeshSplitter::SetCustomDataInTexcoord(UStaticMeshComponent* StaticMeshComponent, int32 textureCoordIndex, FVector2D customData) {
    return {};
}

void UFLStaticMeshSplitter::RemoveCollisionFromLodSections(UStaticMeshComponent* StaticMeshComponent) {
}

FVector2D UFLStaticMeshSplitter::PackTintAndTextureIndex(FLinearColor Tint, int32 TextureIndex) {
    return {};
}

void UFLStaticMeshSplitter::CreateEmptyLod(UStaticMeshComponent* StaticMeshComponent) {
}

void UFLStaticMeshSplitter::CreateCopyOfExistingLod(UStaticMeshComponent* StaticMeshComponent, int32 sourceLodIndex) {
}

void UFLStaticMeshSplitter::BuildStaticMesh(UStaticMesh* StaticMesh) {
}

