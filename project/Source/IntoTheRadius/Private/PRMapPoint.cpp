#include "PRMapPoint.h"
#include "Components/SceneComponent.h"
#include "ITRDefaults.h"

APRMapPoint::APRMapPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USceneComponent* Sub0 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("Root")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::Set(GetClass(), this, TEXT("pointTag.TagName"), TEXT("None"));
}

