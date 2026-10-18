#include "PRItemInfo.h"

#include "ITRDefaults.h"
FPRItemInfo::FPRItemInfo() {
    ActorClass = {};
    ProxyClass = {};
    DestroyedAtZeroDurability = {};
    ChangeWeightFromDurability = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("AttachmentTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("DestroyedAtZeroDurability"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.SellPriceOverride"), (double)-1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.BuyPrice"), (double)-1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Prices.ItemTransformInSlot.Scale3D.Z"), (double)1);
}

FPRItemInfo::~FPRItemInfo() {
}
