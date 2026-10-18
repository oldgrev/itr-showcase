#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemDamagedDelegate.generated.h"

class AActor;
class UDamageType;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FItemDamagedDelegate, AActor*, causer, float, Damage, FGameplayTag, weaponTag, const UDamageType*, DamageType);
