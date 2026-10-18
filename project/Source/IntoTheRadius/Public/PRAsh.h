#pragma once

#include "CoreMinimal.h"
#include "EPRPlatformType.h"
#include "FollowPlayerData.h"
#include "PRBasicActor.h"
#include "PRAsh.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRAsh : public APRBasicActor {
    GENERATED_BODY()
public:
    APRAsh(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere)
    TMap<EPRPlatformType, FFollowPlayerData> FollowPlayerDataMap;
};
