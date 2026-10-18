#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RadiusGameData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API URadiusGameData : public USaveGame {
    GENERATED_BODY()
public:
    URadiusGameData(const FObjectInitializer& ObjectInitializer);

};
