#include "PRAnomaly.h"
#include "Components/AudioComponent.h"
#include "Components/SceneComponent.h"
#include "ITRDefaults.h"

APRAnomaly::APRAnomaly(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USceneComponent* Sub0 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("Root")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    UAudioComponent* Sub1 = Cast<UAudioComponent>(GetDefaultSubobjectByName(TEXT("Audio")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
    Sub1->SetupAttachment(Sub0);
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Audio"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::Set(GetClass(), this, TEXT("AnomalyRadius"), (double)300);
    ITRDefaults::SetObject(GetClass(), this, TEXT("Root"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Audio"), GetDefaultSubobjectByName(TEXT("Audio")));
    ITRDefaults::Set(GetClass(), this, TEXT("MinVisTrigger"), (double)40);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxVisTrigger"), (double)120);
    ITRDefaults::Set(GetClass(), this, TEXT("SignificanceDistance"), (double)10000);
    ITRDefaults::Set(GetClass(), this, TEXT("EffectDelay"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("TypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("Significant"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("TriggeredOverlapCheckTimer"), (double)0.300000012);
    ITRDefaults::Set(GetClass(), this, TEXT("IsSoundConstant"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("DotDuration"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapTriggerTimerHandle.Handle"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapCheckerTimer.Handle"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("significantTimer.Handle"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelfTriggerTimer.Handle"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("discoverTimer.Handle"), (double)0);
}

void APRAnomaly::TriggerVisuals() {
}

void APRAnomaly::OverlapCheckerDelegate() {
}

void APRAnomaly::OnOverlapEndTrigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void APRAnomaly::OnOverlapBeginTrigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void APRAnomaly::LevelStarted(FGameplayTag LevelTag) {
}

void APRAnomaly::LevelPrepare(FGameplayTag LevelTag) {
}

void APRAnomaly::GenerateTriggersOverlapEvents(bool ClearExistingEvents) {
}

void APRAnomaly::ApplyAnomalyDamage(AActor* Actor) {
}

