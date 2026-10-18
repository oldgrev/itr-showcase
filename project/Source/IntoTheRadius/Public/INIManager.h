#pragma once

#include "CoreMinimal.h"
#include "IPreparable.h"
#include "INIManager.generated.h"

class UINIManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UINIManager : public UObject, public IIPreparable {
    GENERATED_BODY()
public:
    UINIManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TrySetVector(const FString& Filename, const FString& Section, const FString& Key, const FVector Value);

    UFUNCTION(BlueprintCallable)
    bool TrySetString(const FString& Filename, const FString& Section, const FString& Key, const FString& Value);

    UFUNCTION(BlueprintCallable)
    bool TrySetInt(const FString& Filename, const FString& Section, const FString& Key, const int32 Value);

    UFUNCTION(BlueprintCallable)
    bool TrySetFloat(const FString& Filename, const FString& Section, const FString& Key, const float Value);

    UFUNCTION(BlueprintCallable)
    bool TrySetBool(const FString& Filename, const FString& Section, const FString& Key, const bool bValue);

    UFUNCTION(BlueprintCallable)
    FVector TryGetVector(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintCallable)
    FString TryGetString(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintCallable)
    int32 TryGetInt(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintCallable)
    float TryGetFloat(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintCallable)
    bool TryGetBool(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintCallable)
    void StoreInUserSave(const FString& Filename);

    UFUNCTION(BlueprintCallable)
    FString GetStringSilent(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintPure)
    static UINIManager* GetINIManager();

    UFUNCTION(BlueprintCallable)
    float GetFloatSilent(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintCallable)
    bool GetBoolSilent(const FString& Filename, const FString& Section, const FString& Key);

    UFUNCTION(BlueprintCallable)
    bool Exists(const FString& Filename, const FString& Section, const FString& Key);

};
