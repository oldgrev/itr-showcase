#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ERadiusCommonStatisticsType.h"
#include "IPreparable.h"
#include "RadiusGameStatistics.generated.h"

class URadiusGameStatistics;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API URadiusGameStatistics : public UObject, public IIPreparable {
    GENERATED_BODY()
public:
    URadiusGameStatistics(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FString GetStatisticsValueString(const ERadiusCommonStatisticsType Type) const;

    UFUNCTION(BlueprintCallable)
    FText GetStatisticsTitle(const ERadiusCommonStatisticsType Type) const;

private:
    UFUNCTION(BlueprintPure)
    static void GetRadiusGameStatistics(URadiusGameStatistics*& RadiusGameStatistics);

public:
    UFUNCTION(BlueprintCallable)
    void GetPlayerKills(TMap<FGameplayTag, int32>& Enemies, TMap<FGameplayTag, int32>& Weapon) const;

    UFUNCTION(BlueprintCallable)
    void GetPlayerDeaths(TMap<FGameplayTag, int32>& Deaths) const;

};
