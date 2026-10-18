#include "PRGrassAnomaly.h"
#include "ITRDefaults.h"

APRGrassAnomaly::APRGrassAnomaly(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Audio"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0.100000001);
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Root"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Audio"), GetDefaultSubobjectByName(TEXT("Audio")));
    ITRDefaults::Set(GetClass(), this, TEXT("MinScaleValue"), (double)-20);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxScaleValue"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ShrinkRatio"), (double)0.0299999993);
    ITRDefaults::Set(GetClass(), this, TEXT("GrowthRatio"), (double)0.0500000007);
    ITRDefaults::Set(GetClass(), this, TEXT("DamageHeight"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("ComponentParameterBase.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ComponentParameterBase.Y"), (double)0.00499999989);
    ITRDefaults::Set(GetClass(), this, TEXT("ComponentParameterBase.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ComponentParameterRatio.X"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("ComponentParameterRatio.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ComponentParameterRatio.Z"), (double)0);
}

void APRGrassAnomaly::ReduceComponent(const int32 Index, const float Value) {
}

void APRGrassAnomaly::Initialize() {
}

