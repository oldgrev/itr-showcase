#pragma once

#include "CoreMinimal.h"
#include "EPRStatStatus.h"
#include "StatStatusEventDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatStatusEvent, EPRStatStatus, Status);
