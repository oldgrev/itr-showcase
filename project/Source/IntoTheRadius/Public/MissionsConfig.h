#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IAsset.h"
#include "IPreparable.h"
#include "MissionsCategory.h"
#include "MissionsConfig.generated.h"

class UMissionNormalConfig;
class UMissionsConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionsConfig : public UDataAsset, public IIAsset, public IIPreparable {
    GENERATED_BODY()
public:
    UMissionsConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static UMissionsConfig* GetMissionsConfig();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UMissionNormalConfig* TutorialMissionConfig;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FMissionsCategory> Missions;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxExecuting;
};
