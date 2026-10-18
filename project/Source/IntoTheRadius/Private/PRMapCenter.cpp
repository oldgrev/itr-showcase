#include "PRMapCenter.h"
#include "Components/SceneComponent.h"
#include "ITRDefaults.h"

APRMapCenter::APRMapCenter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USceneComponent* Sub0 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("Root")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    ITRDefaults::Set(GetClass(), this, TEXT("bIsEditorOnlyActor"), true);
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Root")));
    ITRDefaults::Set(GetClass(), this, TEXT("LevelTag.TagName"), TEXT("None"));
}

