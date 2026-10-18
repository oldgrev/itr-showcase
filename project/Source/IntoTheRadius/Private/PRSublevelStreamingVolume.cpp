#include "PRSublevelStreamingVolume.h"
#include "Components/BoxComponent.h"
#include "ITRDefaults.h"

APRSublevelStreamingVolume::APRSublevelStreamingVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UBoxComponent* Sub0 = Cast<UBoxComponent>(GetDefaultSubobjectByName(TEXT("BoxVolume")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxVolume"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("BoxVolume"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("BoxExtent.X"), (double)100);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BoxExtent.Y"), (double)100);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BoxExtent.Z"), (double)100);
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("ShapeBodySetup"), GetDefaultSubobjectByName(TEXT("BodySetup_2147482630")));
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.B"), (double)255);
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.G"), (double)255);
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.R"), (double)255);
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.A"), (double)255);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("BoxVolume")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BoxVolume"), GetDefaultSubobjectByName(TEXT("BoxVolume")));
    ITRDefaults::Set(GetClass(), this, TEXT("VolumeExtent.X"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("VolumeExtent.Y"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("VolumeExtent.Z"), (double)100);
}

void APRSublevelStreamingVolume::UpdateVolume() {
}

void APRSublevelStreamingVolume::Reset() {
}

void APRSublevelStreamingVolume::OnTransitionStart_Implementation() {
}

void APRSublevelStreamingVolume::OnTransitionEnd_Implementation() {
}

void APRSublevelStreamingVolume::OnLevelStarted_Implementation(FGameplayTag LevelTag) {
}

void APRSublevelStreamingVolume::OnLevelPrepare_Implementation(FGameplayTag LevelTag) {
}

void APRSublevelStreamingVolume::OnGameStartedPrivate() {
}

void APRSublevelStreamingVolume::OnGameStarted_Implementation() {
}

void APRSublevelStreamingVolume::LoadSublevels(bool evented) {
}

bool APRSublevelStreamingVolume::IsLoaded() {
    return {};
}

bool APRSublevelStreamingVolume::CheckSphere(FVector Center, float Radius, float Coefficient) {
    return {};
}

bool APRSublevelStreamingVolume::CheckLocation(FVector Location, float Coefficient) {
    return {};
}

