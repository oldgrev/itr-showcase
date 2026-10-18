#include "HolsterComponent.h"
#include "ITRDefaults.h"

UHolsterComponent::UHolsterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("InventoryModes"), (double)2);
}

void UHolsterComponent::CheckInteractionMode(const EInventoryMode Mode, bool& allow) const {
}

