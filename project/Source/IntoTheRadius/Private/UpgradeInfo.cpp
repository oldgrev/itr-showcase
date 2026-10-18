#include "UpgradeInfo.h"

#include "ITRDefaults.h"
FUpgradeInfo::FUpgradeInfo() {
    Icon = {};
    InstallPrice = {};
    ShowInInfo = {};
    bUseCamoSkin = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("UpgradeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.SellPriceOverride"), (double)-1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.BuyPrice"), (double)-1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemPricesChange.ItemTransformInSlot.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParametersChange.RecoilLocationOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParametersChange.RecoilLocationOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParametersChange.RecoilLocationOffset.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParametersChange.StabilizedRecoilLocationOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParametersChange.StabilizedRecoilLocationOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParametersChange.StabilizedRecoilLocationOffset.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("WeaponParametersChange.TwoHandSmoothingDistance"), (double)50);
}

FUpgradeInfo::~FUpgradeInfo() {
}
