#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLMissionData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLMissionData : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLMissionData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void SetString(const FGameplayTag MissionConfigId, const FString& Key, const FString& Value);

    UFUNCTION(BlueprintCallable)
    static void SetInt(const FGameplayTag MissionConfigId, const FString Key, int32 Value);

    UFUNCTION(BlueprintCallable)
    static void SetFloat(const FGameplayTag MissionConfigId, const FString Key, float Value);

    UFUNCTION(BlueprintCallable)
    static void SetBool(const FGameplayTag MissionConfigId, const FString Key, bool Value);

    UFUNCTION(BlueprintPure)
    static void GetString(const FGameplayTag MissionConfigId, const FString& Key, FString& Value, bool& IsSet);

    UFUNCTION(BlueprintPure)
    static void GetInt(const FGameplayTag MissionConfigId, const FString Key, int32& Value, bool& IsSet);

    UFUNCTION(BlueprintPure)
    static void GetFloat(const FGameplayTag MissionConfigId, const FString Key, float& Value, bool& IsSet);

    UFUNCTION(BlueprintPure)
    static void GetBool(const FGameplayTag MissionConfigId, const FString Key, bool& Value, bool& IsSet);

    UFUNCTION(BlueprintCallable)
    static void CleanUp(const FGameplayTag MissionConfigId);

};
