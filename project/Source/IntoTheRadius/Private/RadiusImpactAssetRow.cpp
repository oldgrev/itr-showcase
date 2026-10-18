#include "RadiusImpactAssetRow.h"

#include "ITRDefaults.h"
FRadiusImpactAssetRow::FRadiusImpactAssetRow() {
    Surface = {};
    Particle = {};
    ParticleScale = {};
    DEcal = {};
    DecalScale = {};
    Sound = {};
    SoundDelay = {};
    VolumnMulti = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ParticleScale"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DecalScale"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("VolumnMulti"), (double)1);
}
