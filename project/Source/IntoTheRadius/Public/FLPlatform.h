#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EPRControllerType.h"
#include "EPRHand.h"
#include "EPRHmdDeviceType.h"
#include "EPRPlatformType.h"
#include "FingerCurls.h"
#include "FLPlatform.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLPlatform : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLPlatform(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static bool IsVRControllerDefault();

    UFUNCTION(BlueprintPure)
    static bool IsPlatformQuest3();

    UFUNCTION(BlueprintPure)
    static bool IsPlatformAndroid();

    UFUNCTION(BlueprintCallable)
    static bool IsNativeOculus();

    UFUNCTION(BlueprintCallable)
    static bool HasVRFocus();

    UFUNCTION(BlueprintPure)
    static EPRControllerType GetVRControllerType();

    UFUNCTION(BlueprintPure)
    static FString GetPlatformTypeString();

    UFUNCTION(BlueprintPure)
    static EPRPlatformType GetPlatformType();

    UFUNCTION(BlueprintPure)
    static void GetPixelDensityScale(float& ScaleX, float& ScaleY);

    UFUNCTION(BlueprintPure)
    static FIntPoint GetIdealRenderTargetSize();

    UFUNCTION(BlueprintPure)
    static EPRHmdDeviceType GetHMDDeviceType();

    UFUNCTION(BlueprintPure)
    static FString GetGPUBrandName();

    UFUNCTION(BlueprintPure)
    static void GetFingerCurls(const EPRHand hand, FFingerCurls& FingerCurls);

    UFUNCTION(BlueprintPure)
    static EPRControllerType GetDefaultControllerType(EPRHmdDeviceType HMDDevice);

    UFUNCTION(BlueprintPure)
    static void GetCurlsAndSplaysState(bool& LeftHandState, bool& RightHandState);

    UFUNCTION(BlueprintPure)
    static FString GetCPUVendorName();

    UFUNCTION(BlueprintPure)
    static FString GetCPUBrandName();

};
