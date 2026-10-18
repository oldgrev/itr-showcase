#include "EnemyDiscoverCriteriaDescription.h"
#include "ITRDefaults.h"

UEnemyDiscoverCriteriaDescription::UEnemyDiscoverCriteriaDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.EnemyDiscoverCriteriaDescription"));
}

