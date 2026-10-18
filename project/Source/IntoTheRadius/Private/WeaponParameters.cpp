#include "WeaponParameters.h"

#include "ITRDefaults.h"
FWeaponParameters::FWeaponParameters() {
    FireRate = {};
    ShotLoudness = {};
    MuzzleVelocity = {};
    AmmoDamage = {};
    DurabilityDamagePerShot = {};
    DurabilityDamageAutoFireCoefficient = {};
    Reliability = {};
    JamCurve = {};
    bDisableSmoothing = {};
    TwoHandSmoothingAlpha = {};
    TwoHandSmoothingDistance = {};
    BurstModeCount = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("TwoHandSmoothingDistance"), (double)50);
    ITRDefaults::Set(StaticStruct(), this, TEXT("BurstModeCount"), (double)3);
}

FWeaponParameters::~FWeaponParameters() {
}
