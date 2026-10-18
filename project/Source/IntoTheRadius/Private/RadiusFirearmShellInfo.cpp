#include "RadiusFirearmShellInfo.h"

#include "ITRDefaults.h"
FRadiusFirearmShellInfo::FRadiusFirearmShellInfo() {
    IsFired = {};
    IsMetal = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("AmmoTag.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("LinearImpulse.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LinearImpulse.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LinearImpulse.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AngularImpulse.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AngularImpulse.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AngularImpulse.Z"), (double)0);
}
