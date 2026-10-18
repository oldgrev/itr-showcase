#include "PRTransitionHint.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "ITRDefaults.h"

APRTransitionHint::APRTransitionHint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USceneComponent* Sub0 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("Root")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    USceneComponent* Sub1 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("Pivot_Hint")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot_Hint"));
    UWidgetComponent* Sub2 = Cast<UWidgetComponent>(GetDefaultSubobjectByName(TEXT("W_Hint")));
    if (!Sub2) Sub2 = CreateDefaultSubobject<UWidgetComponent>(TEXT("W_Hint"));
    Sub1->SetupAttachment(Sub0);
    Sub2->SetupAttachment(Sub1);
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Pivot_Hint"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("W_Hint"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Root"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("HintWidgetParentComponent"), GetDefaultSubobjectByName(TEXT("Pivot_Hint")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("HintWidgetComponent"), GetDefaultSubobjectByName(TEXT("W_Hint")));
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.Transform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.QuadSize.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.QuadSize.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.UVRect.Min.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.UVRect.Min.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.UVRect.Max.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.UVRect.Max.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.UVRect.bIsValid"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.DeltaRotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.DeltaRotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.DeltaRotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.DeltaRotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Quest.LerpToHeadsetLocalSpeed"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.Transform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.QuadSize.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.QuadSize.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.UVRect.Min.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.UVRect.Min.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.UVRect.Max.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.UVRect.Max.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.UVRect.bIsValid"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.DeltaRotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.DeltaRotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.DeltaRotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.DeltaRotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SplashDescForHint_Pico.LerpToHeadsetLocalSpeed"), (double)0.200000003);
}

void APRTransitionHint::ShowTransitionHint() {
}

void APRTransitionHint::HideTransitionHint() {
}

