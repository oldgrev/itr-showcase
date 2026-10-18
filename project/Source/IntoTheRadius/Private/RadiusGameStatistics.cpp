#include "RadiusGameStatistics.h"

URadiusGameStatistics::URadiusGameStatistics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FString URadiusGameStatistics::GetStatisticsValueString(const ERadiusCommonStatisticsType Type) const {
    return {};
}

FText URadiusGameStatistics::GetStatisticsTitle(const ERadiusCommonStatisticsType Type) const {
    return {};
}

void URadiusGameStatistics::GetRadiusGameStatistics(URadiusGameStatistics*& RadiusGameStatistics) {
}

void URadiusGameStatistics::GetPlayerKills(TMap<FGameplayTag, int32>& Enemies, TMap<FGameplayTag, int32>& Weapon) const {
}

void URadiusGameStatistics::GetPlayerDeaths(TMap<FGameplayTag, int32>& Deaths) const {
}

