#include "PRSplashDesc.h"

#include "ITRDefaults.h"
FPRSplashDesc::FPRSplashDesc() {
    bIgnoreAlpha = {};
    bIsDynamic = {};
    bIsExternal = {};
    bLerpToHeadsetLocal = {};
    LerpToHeadsetLocalSpeed = {};
    Texture = {};
    LeftTexture = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("QuadSize.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("QuadSize.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("UVRect.Min.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("UVRect.Min.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("UVRect.Max.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("UVRect.Max.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("UVRect.bIsValid"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DeltaRotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DeltaRotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DeltaRotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DeltaRotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LerpToHeadsetLocalSpeed"), (double)0.200000003);
}
