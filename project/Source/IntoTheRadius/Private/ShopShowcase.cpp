#include "ShopShowcase.h"
#include "Components/SceneComponent.h"
#include "ITRDefaults.h"

AShopShowcase::AShopShowcase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USceneComponent* Sub0 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("RootComponent")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    USceneComponent* Sub1 = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("ShowcaseItems")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<USceneComponent>(TEXT("ShowcaseItems"));
    Sub1->SetupAttachment(Sub0);
    if (UObject* S = GetDefaultSubobjectByName(TEXT("ShowcaseItems"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("RootComponent")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("ItemInShowcaseRoot"), GetDefaultSubobjectByName(TEXT("ShowcaseItems")));
}

void AShopShowcase::SwitchToIndex(int32 Index) {
}

void AShopShowcase::SetUnlockedTypes(const TArray<FGameplayTag>& GameplayTag) {
}

int32 AShopShowcase::GetSelectedIndex() const {
    return {};
}

