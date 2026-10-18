#pragma once

#include "CoreMinimal.h"
#include "IClearable.h"
#include "NoParamsDelegate.h"
#include "TimeManager.generated.h"

class UTimeManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UTimeManager : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UTimeManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static bool SetDateTime(const FDateTime NewDateTime);

    UFUNCTION(BlueprintCallable)
    bool IsNight() const;

    UFUNCTION(BlueprintCallable)
    bool IsDay() const;

    UFUNCTION(BlueprintPure)
    static UTimeManager* GetTimeManager();

    UFUNCTION(BlueprintCallable)
    void GetTime(int32& Hour, int32& Minute);

    UFUNCTION(BlueprintPure)
    float GetSecondsTill(const float Hour);

    UFUNCTION(BlueprintPure)
    static float GetSecondsPassed();

    UFUNCTION(BlueprintPure)
    static float GetHoursPassed();

    UFUNCTION(BlueprintCallable)
    float GetHour();

    UFUNCTION(BlueprintCallable)
    void GetDateTimeStrings(FString& Date, FString& DayOfWeek, FString& Hour, FString& Minute, FString& Second);

    UFUNCTION(BlueprintCallable)
    static FDateTime GetDateTime();

    UFUNCTION(BlueprintCallable)
    void DebugSetHour(const float Hour);

    UFUNCTION(BlueprintCallable)
    void AddTimeTill(float Hour);

    UFUNCTION(BlueprintCallable)
    void AddSeconds(const float Seconds);

    UFUNCTION(BlueprintCallable)
    void AddHours(const float Hours);

    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnNightStart;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnNightEnd;
};
