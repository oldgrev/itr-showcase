#include "PRMapMarker.h"
#include "ITRDefaults.h"

APRMapMarker::APRMapMarker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("MarkerID.TagName"), TEXT("None"));
}

bool APRMapMarker::IsConditionsPassed() {
    return {};
}

