#include "ReflectorAnomlyNonplayerTarget.h"

#include "ITRDefaults.h"
FReflectorAnomlyNonplayerTarget::FReflectorAnomlyNonplayerTarget() {
    ActorRef = {};
    SpinTime = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ActorLocation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ActorLocation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ActorLocation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ShootLocation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ShootLocation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ShootLocation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ActorVelocity.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ActorVelocity.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ActorVelocity.Z"), (double)0);
}
