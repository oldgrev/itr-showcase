#include "PRClusterPattern.h"
#include "Components/SceneComponent.h"
#include "ITRDefaults.h"

APRClusterPattern::APRClusterPattern(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USceneComponent* Sub0 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("Root")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Root"), GetDefaultSubobjectByName(TEXT("Root")));
}

