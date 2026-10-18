#pragma once

#include "CoreMinimal.h"
#include "OnDamagedDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDamaged, AActor*, Actor, float, Damage);
