#pragma once

#include "CoreMinimal.h"
#include "RadiusGameDifficulty.h"
#include "RadiusGameInstanceInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API URadiusGameInstanceInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IRadiusGameInstanceInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void StartNewGame(const int32 ProfileNumber, const bool bSkipTutorial, const bool bIronman, const FRadiusGameDifficulty GameDifficulty, const bool bFromMainMenu);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void LoadGame(const int32 SlotNr, const int32 SaveNr);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ExitGame(const bool bMenu, const bool bSave);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ContinueLastGameInSlot(const int32 SlotNr);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ContinueLastGame();

};
