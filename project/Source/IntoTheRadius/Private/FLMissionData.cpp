#include "FLMissionData.h"

UFLMissionData::UFLMissionData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UFLMissionData::SetString(const FGameplayTag MissionConfigId, const FString& Key, const FString& Value) {
}

void UFLMissionData::SetInt(const FGameplayTag MissionConfigId, const FString Key, int32 Value) {
}

void UFLMissionData::SetFloat(const FGameplayTag MissionConfigId, const FString Key, float Value) {
}

void UFLMissionData::SetBool(const FGameplayTag MissionConfigId, const FString Key, bool Value) {
}

void UFLMissionData::GetString(const FGameplayTag MissionConfigId, const FString& Key, FString& Value, bool& IsSet) {
}

void UFLMissionData::GetInt(const FGameplayTag MissionConfigId, const FString Key, int32& Value, bool& IsSet) {
}

void UFLMissionData::GetFloat(const FGameplayTag MissionConfigId, const FString Key, float& Value, bool& IsSet) {
}

void UFLMissionData::GetBool(const FGameplayTag MissionConfigId, const FString Key, bool& Value, bool& IsSet) {
}

void UFLMissionData::CleanUp(const FGameplayTag MissionConfigId) {
}

