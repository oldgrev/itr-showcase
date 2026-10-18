#pragma once

#include "CoreMinimal.h"
#include "PlayerLostDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerLostDelegate, AActor*, Actor, FVector, LocLastSeen);
