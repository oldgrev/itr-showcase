#include "NPCAwarenessValues.h"

#include "ITRDefaults.h"
FNPCAwarenessValues::FNPCAwarenessValues() {
    NoiseFootsteps = {};
    NoiseWeaponSounds = {};
    NoiseWeaponShot = {};
    DamageMultiplier = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("NoiseFootsteps"), (double)3);
    ITRDefaults::Set(StaticStruct(), this, TEXT("NoiseWeaponSounds"), (double)10);
    ITRDefaults::Set(StaticStruct(), this, TEXT("NoiseWeaponShot"), (double)20);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DamageMultiplier"), (double)2);
}
