#include "PlayerGameData.h"
#include "ITRDefaults.h"

UPlayerGameData::UPlayerGameData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("Health"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxHealth"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("Stamina"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxStamina"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("Rest"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxRest"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxHunger"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("Nutrition"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxNutrition"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionLevel.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionVelocity.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionVelocity.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PositionVelocity.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ZoneEnterLocation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ZoneEnterLocation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ZoneEnterLocation.Z"), (double)0);
}

FString UPlayerGameData::ToString() const {
    return {};
}

void UPlayerGameData::SavePosition(const FGameplayTag InLevel, const FTransform Position, const FVector Velocity) {
}

void UPlayerGameData::SaveDroppedItems(const FGameplayTag InLevel, const FTransform Location, const TArray<FString> ItemIds) {
}

void UPlayerGameData::ResetStats(const bool bAlive) {
}

void UPlayerGameData::ResetPosition() {
}

void UPlayerGameData::RemoveDroppedItem(const FGameplayTag InLevel, const FString ItemId, bool& bEmpty) {
}

void UPlayerGameData::GetPosition(const FGameplayTag InLevel, FTransform& Position, FVector& Velocity, bool& hasSaved) const {
}

TArray<FItemDropInfo> UPlayerGameData::GetDroppedItems(const FGameplayTag InLevel) {
    return {};
}

