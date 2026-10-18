#include "PRPlayerController.h"
#include "ITRDefaults.h"

APRPlayerController::APRPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    if (UObject* S = GetDefaultSubobjectByName(TEXT("TransformComponent0"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bAbsoluteRotation"), true);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("TransformComponent0")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("TransformComponent"), GetDefaultSubobjectByName(TEXT("TransformComponent0")));
    ITRDefaults::Set(GetClass(), this, TEXT("CheatClass"), TEXT("/Script/IntoTheRadius.PRCheatManager"));
}

void APRPlayerController::ReportReady() {
}

bool APRPlayerController::IsPossessingPlayer() const {
    return {};
}

