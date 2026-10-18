#include "RadiusProfilingCamera.h"
#include "ITRDefaults.h"

ARadiusProfilingCamera::ARadiusProfilingCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    if (UObject* S = GetDefaultSubobjectByName(TEXT("CameraComponent"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bConstrainAspectRatio"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("SceneComponent")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("CameraComponent"), GetDefaultSubobjectByName(TEXT("CameraComponent")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("SceneComponent"), GetDefaultSubobjectByName(TEXT("SceneComponent")));
}

