#pragma once

#include "CoreMinimal.h"
#include "IClearable.h"
#include "IPreparable.h"
#include "SaveInfo.h"
#include "SaveSlotInfo.h"
#include "DataSaveManager.generated.h"

class UDataSaveManager;
class UInventoryItem;
class UPRGameData;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UDataSaveManager : public UObject, public IIPreparable, public IIClearable {
    GENERATED_BODY()
public:
    UDataSaveManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetUseAlternateSaveLocation(bool Value);

    UFUNCTION(BlueprintCallable)
    static bool SaveStringToFileEditor(const FString& String, const FString& FilePath, const bool bAppend);

    UFUNCTION(BlueprintCallable)
    static bool SaveStringToFile(const FString& String, const FString& FilePath, const bool bAppend);

    UFUNCTION(BlueprintCallable)
    void SaveGameData(UPRGameData* Data, int32 SlotNr, int32 SaveNr);

    UFUNCTION(BlueprintPure)
    bool IsSlotWithIronman(const int32 Slot);

    UFUNCTION(BlueprintPure)
    static bool IsSlotEmpty(const FSaveSlotInfo& SlotInfo);

    UFUNCTION(BlueprintPure)
    bool HasSaves();

    UFUNCTION(BlueprintCallable)
    bool GetUseAlternateSaveLocation() const;

    UFUNCTION(BlueprintCallable)
    bool GetSlotInfo(const int32 Slot, FSaveSlotInfo& SlotInfo);

    UFUNCTION(BlueprintPure)
    static FString GetSavesPath();

    UFUNCTION(BlueprintCallable)
    bool GetSaveInfo(const int32 Slot, const int32 Save, FSaveInfo& SaveInfo);

    UFUNCTION(BlueprintPure)
    static FSaveInfo GetLastSaveInfo(FSaveSlotInfo SlotInfo);

    UFUNCTION(BlueprintPure)
    static UDataSaveManager* GetDataSaveManager();

    UFUNCTION(BlueprintPure)
    static FString GetDataPath();

    UFUNCTION(BlueprintCallable)
    static bool FixInventoryItemPosition(UInventoryItem* Item);

    UFUNCTION(BlueprintCallable)
    void CopyScopedToAlternateSave();

    UFUNCTION(BlueprintCallable)
    void CopyAlternateToScopedSave();

    UFUNCTION(BlueprintCallable)
    void AutosaveGameData(const FString& Message);

};
