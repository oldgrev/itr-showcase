#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IPRPlayerController.h"
#include "ReadyMarkInterface.h"
#include "PRPlayerController.generated.h"

UCLASS(Blueprintable, BlueprintType, Config=Game)
class INTOTHERADIUS_API APRPlayerController : public APlayerController, public IIPRPlayerController, public IReadyMarkInterface {
    GENERATED_BODY()
public:
    APRPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void ReportReady();

public:
    UFUNCTION(BlueprintCallable)
    bool IsPossessingPlayer() const;

};
