#pragma once

#include "CoreMinimal.h"
#include "IngameMenuControllerInterface.h"
#include "PRBasicActor.h"
#include "IngameMenuController.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API AIngameMenuController : public APRBasicActor, public IIngameMenuControllerInterface {
    GENERATED_BODY()
public:
    AIngameMenuController(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnIngameMenuDeactivated();

    UFUNCTION(BlueprintImplementableEvent)
    void OnIngameMenuActivated();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> ingameMenuClass;
private:
    UPROPERTY()
    AActor* _ingameMenu;
};
