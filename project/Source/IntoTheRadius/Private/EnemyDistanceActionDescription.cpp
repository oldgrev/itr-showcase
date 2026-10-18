#include "EnemyDistanceActionDescription.h"
#include "ITRDefaults.h"

UEnemyDistanceActionDescription::UEnemyDistanceActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.EnemyDistanceActionDescription"));
}

