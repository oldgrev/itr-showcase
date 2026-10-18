#pragma once

#include "CoreMinimal.h"
#include "LightSensitiveManager.generated.h"

class AActor;
class ULightSensitiveManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ULightSensitiveManager : public UObject {
    GENERATED_BODY()
public:
    ULightSensitiveManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnregisterLightSensitiveObject(AActor* LightSensitiveObject);

    UFUNCTION(BlueprintCallable)
    void RegisterLightSensitiveObject(AActor* LightSensitiveObject);

    UFUNCTION(BlueprintPure)
    static ULightSensitiveManager* GetLightSensitiveManager();

};
