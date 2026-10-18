#pragma once

#include "CoreMinimal.h"
#include "EPRHmdDeviceType.generated.h"

UENUM(BlueprintType)
enum class EPRHmdDeviceType : uint8 {
    Unknown = 0,
    PIE = 1,
    ValveIndex = 10,
    Vive = 20,
    ViveCosmos = 21,
    Oculus = 30,
    OculusRiftS = 31,
    WindowsMR = 40,
    Pico = 50,
};
