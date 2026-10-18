#include "RadiusShrapnelComponent.h"
#include "ITRDefaults.h"

URadiusShrapnelComponent::URadiusShrapnelComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxCount"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("BuckShotTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TraceProfileName"), TEXT("Bullet"));
    ITRDefaults::Set(GetClass(), this, TEXT("ParticalScale"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationParticalScale"), (double)1.29999995);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxAccuracySpread"), (double)6);
    ITRDefaults::Set(GetClass(), this, TEXT("MinAccuracySpread"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceStep"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MinTraceDistance"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxDamageScale"), (double)0.100000001);
    ITRDefaults::Set(GetClass(), this, TEXT("MinDamage"), (double)0.100000001);
    ITRDefaults::Set(GetClass(), this, TEXT("DestroyAfterExecute"), true);
}

void URadiusShrapnelComponent::Initialize(const FAmmoInfo& AmmoInfo, float Damage, float Accuracy, FVector Offset, float TraceDistance) {
}

void URadiusShrapnelComponent::Execute() {
}

