#include "DiscoverEnemyActionDescription.h"
#include "ITRDefaults.h"

UDiscoverEnemyActionDescription::UDiscoverEnemyActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.DiscoverEnemyActionDescription"));
}

