#pragma once

#include "CoreMinimal.h"
#include "EHapticsType.generated.h"

UENUM(BlueprintType)
enum class EHapticsType : uint8 {
    None = 0,
    Death = 1,
    DistanceGrip_Left = 2,
    DistanceGrip_Right = 3,
    BulletHit = 6,
    Climb_Left = 7,
    Climb_Right = 8,
    Ping_Left = 9,
    Ping_Right = 10,
    Rumble = 11,
    Heartbeat = 12,
    BackpackTake = 13,
    BackpackReturn = 14,
    Eat = 15,
    Drink = 16,
    Smoke = 17,
    SitDown = 18,
    Inject = 19,
    Inject_Left = 20,
    Inject_Right = 21,
    Ping_Chest_Left = 22,
    Ping_Chest_Right = 23,
    KnifeHit_Left = 24,
    KnifeHit_Right = 25,
    DamageFall_Light = 31,
    DamageFall_Heavy = 32,
    DamageSlash_Front_Left = 33,
    DamageSlash_Back_Left = 34,
    DamageSlash_Front_Right = 35,
    DamageSlash_Back_Right = 36,
    DamageZone_Light = 37,
    DamageZone_Heavy = 38,
    Recoil_Left = 40,
    Recoil_Right = 41,
    Level_Transfer = 42,
};
