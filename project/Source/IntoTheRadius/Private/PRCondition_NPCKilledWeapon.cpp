#include "PRCondition_NPCKilledWeapon.h"
#include "ITRDefaults.h"

UPRCondition_NPCKilledWeapon::UPRCondition_NPCKilledWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("WeaponTypeID.TagName"), TEXT("None"));
}

