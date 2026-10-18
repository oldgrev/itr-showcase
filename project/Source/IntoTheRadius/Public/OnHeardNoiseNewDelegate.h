#pragma once

#include "CoreMinimal.h"
#include "OnHeardNoiseNewDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHeardNoiseNew, FName, Tag, FVector, Loc);
