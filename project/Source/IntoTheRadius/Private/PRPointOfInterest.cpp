#include "PRPointOfInterest.h"
#include "ITRDefaults.h"

APRPointOfInterest::APRPointOfInterest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("bPoiValid"), true);
}

