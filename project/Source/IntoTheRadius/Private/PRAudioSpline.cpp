#include "PRAudioSpline.h"
#include "Components/AudioComponent.h"
#include "Components/SplineComponent.h"
#include "ITRDefaults.h"

APRAudioSpline::APRAudioSpline(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USplineComponent* Sub0 = Cast<USplineComponent>(GetDefaultSubobjectByName(TEXT("Spline")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
    UAudioComponent* Sub1 = Cast<UAudioComponent>(GetDefaultSubobjectByName(TEXT("Audio")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Spline"), GetDefaultSubobjectByName(TEXT("Spline")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Audio"), GetDefaultSubobjectByName(TEXT("Audio")));
}

