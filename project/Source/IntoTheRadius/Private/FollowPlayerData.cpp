#include "FollowPlayerData.h"

#include "ITRDefaults.h"
FFollowPlayerData::FFollowPlayerData() {
    bFollowPlayer = {};
    PlayerFollowVelocityModifier = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("PlayerFollowOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PlayerFollowOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PlayerFollowOffset.Z"), (double)0);
}
