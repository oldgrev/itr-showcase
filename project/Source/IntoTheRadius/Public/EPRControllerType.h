#pragma once

#include "CoreMinimal.h"
#include "EPRControllerType.generated.h"

UENUM(BlueprintType)
enum class EPRControllerType : uint8 {
    Unknown = 0,
    Index = 10,
    Vive = 20,
    ViveCosmos = 21,
    Rift = 30,
    RiftS = 31,
    NativeRift = 40,
    NativeRiftS = 41,
    WMR = 50,
    PicoNeo3 = 60,
    Pico4 = 61,
};
