#include "SpawnerGeneratorAlternativePlace.h"
#include "Components/BillboardComponent.h"
#include "ITRDefaults.h"

ASpawnerGeneratorAlternativePlace::ASpawnerGeneratorAlternativePlace(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UBillboardComponent* Sub0 = Cast<UBillboardComponent>(GetDefaultSubobjectByName(TEXT("Root")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UBillboardComponent>(TEXT("Root"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Root"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("ScreenSize"), (double)0.00100000005);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bIsScreenSizeScaled"), true);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Root")));
}

