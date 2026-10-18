#pragma once

#include "CoreMinimal.h"
#include "Texture2DArrayWrapper.generated.h"

class UTexture2D;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UTexture2DArrayWrapper : public UObject {
    GENERATED_BODY()
public:
    UTexture2DArrayWrapper(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly)
    FString Postfix;
    UPROPERTY(BlueprintReadOnly)
    TArray<UTexture2D*> Textures;
};
