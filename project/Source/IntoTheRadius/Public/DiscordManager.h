#pragma once

#include "CoreMinimal.h"
#include "IClearable.h"
#include "DiscordManager.generated.h"

class UDiscordManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UDiscordManager : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UDiscordManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    void Initialize();

    UFUNCTION(BlueprintPure)
    static UDiscordManager* GetDiscordManager();

    UFUNCTION()
    void ChangeLocationName();

    UFUNCTION()
    void ChangeDifficulty();

};
