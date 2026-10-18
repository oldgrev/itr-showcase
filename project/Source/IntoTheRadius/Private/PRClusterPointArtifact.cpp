#include "PRClusterPointArtifact.h"
#include "Components/BillboardComponent.h"
#include "ITRDefaults.h"

UPRClusterPointArtifact::UPRClusterPointArtifact(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UBillboardComponent* Sub0 = Cast<UBillboardComponent>(GetDefaultSubobjectByName(TEXT("Root")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UBillboardComponent>(TEXT("Root"));
    Sub0->SetupAttachment(this);
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Root"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("ScreenSize"), (double)0.00100000005);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bIsScreenSizeScaled"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("Billboard"), GetDefaultSubobjectByName(TEXT("Root")));
}

