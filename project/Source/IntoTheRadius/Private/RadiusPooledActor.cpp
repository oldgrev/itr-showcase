#include "RadiusPooledActor.h"
#include "ITRDefaults.h"
#include "PoolDisposeComponent.h"

ARadiusPooledActor::ARadiusPooledActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UPoolDisposeComponent* Sub0 = Cast<UPoolDisposeComponent>(GetDefaultSubobjectByName(TEXT("PoolDisposeComponent")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UPoolDisposeComponent>(TEXT("PoolDisposeComponent"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("PoolDisposeComponent"), GetDefaultSubobjectByName(TEXT("PoolDisposeComponent")));
}

