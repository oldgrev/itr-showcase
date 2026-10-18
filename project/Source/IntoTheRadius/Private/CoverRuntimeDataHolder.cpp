#include "CoverRuntimeDataHolder.h"

UCoverRuntimeDataHolder::UCoverRuntimeDataHolder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UCoverRuntimeDataHolder::ToggleDebug() {
}

void UCoverRuntimeDataHolder::OnLevelUnloaded() {
}

bool UCoverRuntimeDataHolder::GetDebugEnabled() const {
    return {};
}

UCoverRuntimeDataHolder* UCoverRuntimeDataHolder::GetCoverRuntimeDataHolder() {
    return {};
}

void UCoverRuntimeDataHolder::DrawShippingDebug(const UObject* WorldContextObject, const FVector CurrentLocation, float Radius) {
}

void UCoverRuntimeDataHolder::DebugDraw(const UObject* WorldContextObject) {
}

