#include "FLPlatform.h"

UFLPlatform::UFLPlatform(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UFLPlatform::IsVRControllerDefault() {
    return {};
}

bool UFLPlatform::IsPlatformQuest3() {
    return {};
}

bool UFLPlatform::IsPlatformAndroid() {
    return {};
}

bool UFLPlatform::IsNativeOculus() {
    return {};
}

bool UFLPlatform::HasVRFocus() {
    return {};
}

EPRControllerType UFLPlatform::GetVRControllerType() {
    return {};
}

FString UFLPlatform::GetPlatformTypeString() {
    return {};
}

EPRPlatformType UFLPlatform::GetPlatformType() {
    return {};
}

void UFLPlatform::GetPixelDensityScale(float& ScaleX, float& ScaleY) {
}

FIntPoint UFLPlatform::GetIdealRenderTargetSize() {
    return {};
}

EPRHmdDeviceType UFLPlatform::GetHMDDeviceType() {
    return {};
}

FString UFLPlatform::GetGPUBrandName() {
    return {};
}

void UFLPlatform::GetFingerCurls(const EPRHand hand, FFingerCurls& FingerCurls) {
}

EPRControllerType UFLPlatform::GetDefaultControllerType(EPRHmdDeviceType HMDDevice) {
    return {};
}

void UFLPlatform::GetCurlsAndSplaysState(bool& LeftHandState, bool& RightHandState) {
}

FString UFLPlatform::GetCPUVendorName() {
    return {};
}

FString UFLPlatform::GetCPUBrandName() {
    return {};
}

