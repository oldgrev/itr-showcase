#include "FLTexture2DArray.h"

UFLTexture2DArray::UFLTexture2DArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

TArray<UTexture2DArrayWrapper*> UFLTexture2DArray::Texture2DArray_SplitTexturesIntoValidGroups(TArray<UTexture2D*> Textures) {
    return {};
}

void UFLTexture2DArray::Texture2DArray_SetTextures(UTexture2DArray* textureArray, TArray<UTexture2D*> Textures) {
}

TArray<UTexture2D*> UFLTexture2DArray::Texture2DArray_GetTextures(UTexture2DArray* textureArray) {
    return {};
}

