#include "RadiusBulletTracerComponent.h"
#include "ITRDefaults.h"

URadiusBulletTracerComponent::URadiusBulletTracerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TracerTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("DebugPrimaryColor.R"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugPrimaryColor.G"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugPrimaryColor.B"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugPrimaryColor.A"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugSecondaryColor.R"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugSecondaryColor.G"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugSecondaryColor.B"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugSecondaryColor.A"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugLineDurarion"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugLineThickness"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("ScaleFactor"), (double)0.0399999991);
    ITRDefaults::Set(GetClass(), this, TEXT("ScaleFactorInputRange.X"), (double)5000);
    ITRDefaults::Set(GetClass(), this, TEXT("ScaleFactorInputRange.Y"), (double)10500);
    ITRDefaults::Set(GetClass(), this, TEXT("ScaleFactorOutputRange.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ScaleFactorOutputRange.Y"), (double)7);
    ITRDefaults::Set(GetClass(), this, TEXT("VelocityTolerance"), (double)1500);
}

void URadiusBulletTracerComponent::Suspend(bool IsSuspend) {
}

void URadiusBulletTracerComponent::Stop() {
}

void URadiusBulletTracerComponent::Start() {
}

void URadiusBulletTracerComponent::Initialize(const bool ForceTracer, const float MinSpeed, const float MaxSpeed, const FGameplayTag AmmoTypeID, const bool DebugMode) {
}

void URadiusBulletTracerComponent::DelayedStart() {
}

