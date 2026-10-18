#include "PlayerProximityCriteriaDescription.h"
#include "ITRDefaults.h"

UPlayerProximityCriteriaDescription::UPlayerProximityCriteriaDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.PlayerProximityCriteriaDescription"));
    ITRDefaults::Set(GetClass(), this, TEXT("PlayerDistancePC"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("PlayerDistanceQuest"), (double)1000);
}

