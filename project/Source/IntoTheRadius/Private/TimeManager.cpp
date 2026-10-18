#include "TimeManager.h"

UTimeManager::UTimeManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UTimeManager::SetDateTime(const FDateTime NewDateTime) {
    return {};
}

bool UTimeManager::IsNight() const {
    return {};
}

bool UTimeManager::IsDay() const {
    return {};
}

UTimeManager* UTimeManager::GetTimeManager() {
    return {};
}

void UTimeManager::GetTime(int32& Hour, int32& Minute) {
}

float UTimeManager::GetSecondsTill(const float Hour) {
    return {};
}

float UTimeManager::GetSecondsPassed() {
    return {};
}

float UTimeManager::GetHoursPassed() {
    return {};
}

float UTimeManager::GetHour() {
    return {};
}

void UTimeManager::GetDateTimeStrings(FString& Date, FString& DayOfWeek, FString& Hour, FString& Minute, FString& Second) {
}

FDateTime UTimeManager::GetDateTime() {
    return {};
}

void UTimeManager::DebugSetHour(const float Hour) {
}

void UTimeManager::AddTimeTill(float Hour) {
}

void UTimeManager::AddSeconds(const float Seconds) {
}

void UTimeManager::AddHours(const float Hours) {
}

