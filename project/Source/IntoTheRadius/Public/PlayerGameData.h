#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IClearable.h"
#include "ItemDropInfo.h"
#include "PlayerGameData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPlayerGameData : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UPlayerGameData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FString ToString() const;

    UFUNCTION(BlueprintCallable)
    void SavePosition(const FGameplayTag InLevel, const FTransform Position, const FVector Velocity);

    UFUNCTION(BlueprintCallable)
    void SaveDroppedItems(const FGameplayTag InLevel, const FTransform Location, const TArray<FString> ItemIds);

    UFUNCTION(BlueprintCallable)
    void ResetStats(const bool bAlive);

    UFUNCTION(BlueprintCallable)
    void ResetPosition();

    UFUNCTION(BlueprintCallable)
    void RemoveDroppedItem(const FGameplayTag InLevel, const FString ItemId, bool& bEmpty);

    UFUNCTION(BlueprintCallable)
    void GetPosition(const FGameplayTag InLevel, FTransform& Position, FVector& Velocity, bool& hasSaved) const;

    UFUNCTION(BlueprintCallable)
    TArray<FItemDropInfo> GetDroppedItems(const FGameplayTag InLevel);

    UPROPERTY(BlueprintReadOnly)
    float Health;
    UPROPERTY(BlueprintReadOnly)
    float MaxHealth;
    UPROPERTY(BlueprintReadOnly)
    float Stamina;
    UPROPERTY(BlueprintReadOnly)
    float MaxStamina;
    UPROPERTY(BlueprintReadOnly)
    float Rest;
    UPROPERTY(BlueprintReadOnly)
    float MaxRest;
    UPROPERTY(BlueprintReadOnly)
    float Hunger;
    UPROPERTY(BlueprintReadOnly)
    float MaxHunger;
    UPROPERTY(BlueprintReadOnly)
    float Nutrition;
    UPROPERTY(BlueprintReadOnly)
    float MaxNutrition;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 Money;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 PlayerLevel;
    UPROPERTY()
    FGameplayTag PositionLevel;
    UPROPERTY()
    FTransform PositionTransform;
    UPROPERTY(BlueprintReadWrite)
    FVector PositionVelocity;
    UPROPERTY(BlueprintReadOnly)
    TMap<FGameplayTag, FVector> LastDeathLocation;
    UPROPERTY(BlueprintReadOnly)
    TMap<FGameplayTag, FVector> LastSleepLocation;
    UPROPERTY(BlueprintReadWrite)
    FVector ZoneEnterLocation;
    UPROPERTY(BlueprintReadWrite)
    TArray<FItemDropInfo> DeathDropItems;
};
