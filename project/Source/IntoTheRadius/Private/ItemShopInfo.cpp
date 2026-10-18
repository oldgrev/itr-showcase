#include "ItemShopInfo.h"

#include "ITRDefaults.h"
FItemShopInfo::FItemShopInfo() {
    SellPriceOverride = {};
    BuyPrice = {};
    RepairPricePerPercent = {};
    RepairSecondsPerPercent = {};
    RequiredPlayerLevel = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("SellPriceOverride"), (double)-1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("BuyPrice"), (double)-1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTransformInSlot.Scale3D.Z"), (double)1);
}
