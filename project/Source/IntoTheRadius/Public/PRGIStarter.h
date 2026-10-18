#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameStarterInterface.h"
#include "PRSplashDesc.h"
#include "ReadyMarkInterface.h"
#include "PRGIStarter.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRGIStarter : public UGameInstance, public IGameStarterInterface, public IReadyMarkInterface {
    GENERATED_BODY()
public:
    UPRGIStarter(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly)
    TArray<FPRSplashDesc> SplashDescriptions;
};
