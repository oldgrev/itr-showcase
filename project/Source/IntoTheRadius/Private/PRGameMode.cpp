#include "PRGameMode.h"
#include "ITRDefaults.h"

APRGameMode::APRGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionStartTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("bRespawnInventory"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("bSleepAllowed"), true);
}

void APRGameMode::TogglePause() {
}

void APRGameMode::SetGameplayTimeDilation(const float Dilation) {
}

void APRGameMode::ResetAutosaveTimer_Native() {
}

void APRGameMode::RecallLevelLoaded() {
}

void APRGameMode::PreparePlayerForFinalChoice() {
}

void APRGameMode::OnLevelUnloaded() {
}

void APRGameMode::OnLevelLoaded() {
}

void APRGameMode::OnGameStarted() {
}

void APRGameMode::OnEditorLevelLoaded() {
}

FString APRGameMode::MakeActorUID(AActor* Actor) {
    return {};
}

void APRGameMode::GetPRGameMode(APRGameMode*& GameMode) {
}

void APRGameMode::GetGameplayTimeDilation(float& Dilation) const {
}

APREnvironment* APRGameMode::GetCurrentEnvironment() {
    return {};
}

FString APRGameMode::GetActorUID(AActor* Actor) {
    return {};
}

void APRGameMode::FinishTransfer() {
}

void APRGameMode::DoTransferToLevel() {
}

void APRGameMode::DoStart() {
}

void APRGameMode::DoPrepare() {
}

void APRGameMode::DoEndTransition() {
}

void APRGameMode::ContinueTransitionLoad() {
}

void APRGameMode::BeginWaitingForPSO() {
}

