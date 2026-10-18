#pragma once

#include "CoreMinimal.h"
#include "PRSplashDesc.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRSplashDesc {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    FTransform Transform;
    UPROPERTY(EditDefaultsOnly)
    FVector2D QuadSize;
    UPROPERTY(EditDefaultsOnly)
    FBox2D UVRect;
    UPROPERTY(EditDefaultsOnly)
    FQuat DeltaRotation;
    UPROPERTY(EditDefaultsOnly)
    bool bIgnoreAlpha;
    UPROPERTY(EditDefaultsOnly)
    bool bIsDynamic;
    UPROPERTY(EditDefaultsOnly)
    bool bIsExternal;
    UPROPERTY(EditDefaultsOnly)
    bool bLerpToHeadsetLocal;
    UPROPERTY(EditDefaultsOnly)
    float LerpToHeadsetLocalSpeed;
    UPROPERTY(EditDefaultsOnly)
    UTexture* Texture;
    UPROPERTY(EditDefaultsOnly)
    UTexture* LeftTexture;
    FPRSplashDesc();
};
