#include "VfxConfig.h"
#include "ITRDefaults.h"

UVfxConfig::UVfxConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.VfxConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDistanceClampInRange.X"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDistanceClampInRange.Y"), (double)150000);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDistanceClampOutRange.X"), (double)0.400000006);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDistanceClampOutRange.Y"), (double)1.20000005);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDisableFlag"), TEXT("itr.performanceDebugging.enableRemoveProjectileEffectsOptim"));
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDefaultRow"), TEXT("SurfaceType_Default"));
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDefaultDecalScale.X"), (double)3.5);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDefaultDecalScale.Y"), (double)3.5);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDefaultDecalScale.Z"), (double)3.5);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactDefaultVolumnMulti"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactOffsetVector.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactOffsetVector.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactOffsetVector.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ImpactSpeedScale"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("BulletTracersStartDelay"), (double)9.99999975e-05);
}

UVfxConfig* UVfxConfig::GetVfxConfig() {
    return {};
}

