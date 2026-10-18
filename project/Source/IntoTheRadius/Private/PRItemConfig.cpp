#include "PRItemConfig.h"
#include "ITRDefaults.h"

UPRItemConfig::UPRItemConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("ConfigID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("HolderID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("Durability"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("Ammo.ChamberAmmo.TagName"), TEXT("None"));
}

UPRItemConfig* UPRItemConfig::CloneWithUID(const FString& newUID) {
    return {};
}

