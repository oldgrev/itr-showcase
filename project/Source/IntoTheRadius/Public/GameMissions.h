#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IClearable.h"
#include "GameMissions.generated.h"

class UMissionData;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UGameMissions : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UGameMissions(const FObjectInitializer& ObjectInitializer);

    UPROPERTY()
    TArray<UMissionData*> ActiveMissions;
    UPROPERTY()
    TMap<FGameplayTag, UMissionData*> ActiveMissionsMap;
    UPROPERTY()
    FString SelectedMissionInstanceID;
    UPROPERTY()
    TArray<FString> SelectedMissions;
    UPROPERTY()
    TArray<UMissionData*> FinishedMissions;
    UPROPERTY(BlueprintReadWrite)
    TMap<FString, int32> CellsPerMission;
};
