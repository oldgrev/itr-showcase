#include "EnvConfigurator.h"
#include "ITRDefaults.h"

AEnvConfigurator::AEnvConfigurator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("bIsEditorOnlyActor"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("LevelTag.TagName"), TEXT("None"));
}

