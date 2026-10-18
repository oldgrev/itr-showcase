#pragma once

#include "CoreMinimal.h"
#include "IItemHolder.h"
#include "PRBasicActor.h"
#include "PRHolder.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRHolder : public APRBasicActor, public IIItemHolder {
    GENERATED_BODY()
public:
    APRHolder(const FObjectInitializer& ObjectInitializer);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<AActor*> OverlappedActors;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisabledInteraction;
};
