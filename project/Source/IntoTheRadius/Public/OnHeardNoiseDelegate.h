#pragma once

#include "CoreMinimal.h"
#include "OnHeardNoiseDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHeardNoise, AActor*, Actor, FVector, Location, float, Strength, FName, Tag);
