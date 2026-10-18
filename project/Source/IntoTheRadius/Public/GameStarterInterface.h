#pragma once

#include "CoreMinimal.h"
#include "GameStarterInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UGameStarterInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IGameStarterInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ShowStartupLoadingSplash() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetPSOTasksNumbers(int32& NumRemaining, int32& NumTotal) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GameStarted() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GameShuttingDown() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void CheckGameStart();

};
