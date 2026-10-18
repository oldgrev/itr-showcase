#pragma once

#include "CoreMinimal.h"
#include "ThreeParamsGameSaveDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FThreeParamsGameSave, int32, Slot, int32, Save, float, SizeMb);
