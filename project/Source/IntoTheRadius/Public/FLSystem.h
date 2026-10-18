#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLSystem.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLSystem : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLSystem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static bool IsSimulate();

    UFUNCTION(BlueprintPure)
    static bool IsShippingBuild();

    UFUNCTION(BlueprintPure)
    static bool IsQABuild();

    UFUNCTION(BlueprintPure)
    static bool IsModKitBuild();

    UFUNCTION(BlueprintPure)
    static bool IsEditor();

    UFUNCTION(BlueprintPure)
    static bool IsDevelopmentBuild();

    UFUNCTION(BlueprintPure)
    static bool IsBuild();

    UFUNCTION(BlueprintPure)
    static FString GetRelevantLanguage();

    UFUNCTION(BlueprintPure)
    static void GetPuTimers(float& RawFrameTime, float& RawGameThreadTime, float& RawrenderThreadTime, float& RawGPUFrameTime);

    UFUNCTION(BlueprintPure)
    static FString GetProjectVersion();

    UFUNCTION(BlueprintPure)
    static FString GetProjectRevision();

    UFUNCTION(BlueprintPure)
    static FString GetProjectBeta();

    UFUNCTION(BlueprintPure)
    static FString GetInstallID();

    UFUNCTION(BlueprintPure)
    static FString GetFullVersionString();

    UFUNCTION(BlueprintPure)
    static FString GetClientVersionString();

};
