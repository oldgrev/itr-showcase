#include "PRSkyBox.h"
#include "ITRDefaults.h"

APRSkyBox::APRSkyBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("RadiusLocation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("RadiusLocation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("RadiusLocation.Z"), (double)0);
}

FVector APRSkyBox::GetRadiusLocation() {
    return {};
}

