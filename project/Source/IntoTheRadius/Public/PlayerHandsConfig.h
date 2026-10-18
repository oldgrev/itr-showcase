#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "EPRControllerType.h"
#include "EPRHandPoseGeometryType.h"
#include "EPRHandPoseNumber.h"
#include "EPRHandPoseType.h"
#include "IAsset.h"
#include "IPreparable.h"
#include "PRCleanTransform.h"
#include "PRHandPoseConditions.h"
#include "PRHandPoseInfo.h"
#include "PRHandPoseInfosPair.h"
#include "ShiftsPair.h"
#include "PlayerHandsConfig.generated.h"

class UDataTable;
class UGripMotionControllerComponent;
class UObject;
class UPlayerHandsConfig;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMesh;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPlayerHandsConfig : public UDataAsset, public IIAsset, public IIPreparable {
    GENERATED_BODY()
public:
    UPlayerHandsConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static FTransform ToTransform(FPRCleanTransform cleanTransform);

    UFUNCTION(BlueprintCallable)
    static void ShowDeviceModel(USceneComponent* Parent, UPrimitiveComponent* DisplayComponent, EControllerHand hand, UPrimitiveComponent*& newDisplayComponent);

    UFUNCTION(BlueprintCallable)
    void SaveToAsset();

    UFUNCTION(BlueprintCallable)
    void SavePoseDefault(TMap<EPRControllerType, FPRCleanTransform> leftItemShifts, TMap<EPRControllerType, FPRCleanTransform> rightItemShifts, FPRHandPoseInfosPair handsData);

    UFUNCTION(BlueprintCallable)
    bool HaveHandsPoseForTagByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, FGameplayTag Tag, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const;

    UFUNCTION(BlueprintCallable)
    bool HaveHandsPoseForTag(const EPRHandPoseType PoseType, const FGameplayTag Tag) const;

    UFUNCTION(BlueprintCallable)
    bool HaveHandsPoseForStaticMeshByGeometryTypeAndPoseNumber(const EPRHandPoseType PoseType, UStaticMesh* StaticMesh, const EPRHandPoseGeometryType GeometryType, const EPRHandPoseNumber PoseNumber) const;

    UFUNCTION(BlueprintCallable)
    bool HaveHandsPoseForStaticMesh(const EPRHandPoseType PoseType, UStaticMesh* StaticMesh) const;

    UFUNCTION(BlueprintCallable)
    bool HaveHandsPoseForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, UObject* Object, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const;

    UFUNCTION(BlueprintCallable)
    bool HaveHandsPoseForObject(EPRHandPoseType PoseType, UObject* Object) const;

    UFUNCTION(BlueprintPure)
    static FTransform GetShiftForController(const FPRHandPoseInfo& Info, const EPRControllerType& Controller);

    UFUNCTION(BlueprintCallable)
    void GetPointShiftForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, FPRHandPoseConditions& HandPoseConditions) const;

    UFUNCTION(BlueprintCallable)
    void GetPointShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform) const;

    UFUNCTION(BlueprintPure)
    static UPlayerHandsConfig* GetPlayerHandsConfig();

    UFUNCTION(BlueprintPure)
    static void GetItemShiftForController(const TMap<EPRControllerType, FTransform>& shiftPerController, const EPRControllerType& Controller, FTransform& Shift);

    UFUNCTION(BlueprintCallable)
    FPRHandPoseInfosPair GetHandsPoseForTagByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, FGameplayTag Tag, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const;

    UFUNCTION(BlueprintCallable)
    FPRHandPoseInfosPair GetHandsPoseForTag(EPRHandPoseType PoseType, FGameplayTag Tag) const;

    UFUNCTION(BlueprintCallable)
    FPRHandPoseInfosPair GetHandsPoseForStaticMeshByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, UStaticMesh* StaticMesh, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const;

    UFUNCTION(BlueprintCallable)
    FPRHandPoseInfosPair GetHandsPoseForStaticMesh(EPRHandPoseType PoseType, UStaticMesh* StaticMesh) const;

    UFUNCTION(BlueprintCallable)
    FPRHandPoseInfosPair GetHandsPoseForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, UObject* Object, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const;

    UFUNCTION(BlueprintCallable)
    FPRHandPoseInfosPair GetHandsPoseForObject(EPRHandPoseType PoseType, UObject* Object) const;

    UFUNCTION(BlueprintCallable)
    void GetHandShiftForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, FPRHandPoseConditions& HandPoseConditions) const;

    UFUNCTION(BlueprintCallable)
    void GetHandShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform) const;

    UFUNCTION(BlueprintCallable)
    void GetControllerShifts(const EPRControllerType Controller, FTransform& LeftShift, FTransform& RightShift);

    UFUNCTION(BlueprintCallable)
    void GetBestPointShiftForObjectByConditions(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool useGripLimit, const FVector& handRootLocation, const UGripMotionControllerComponent* MotionController, bool& success, FTransform& Result, FTransform& WorldTransform, EPRHandPoseGeometryType& bestGeometryType, EPRHandPoseNumber& bestPoseNumber) const;

    UFUNCTION(BlueprintCallable)
    void GetBestPointShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, EPRHandPoseGeometryType& bestGeometryType, EPRHandPoseNumber& bestPoseNumber) const;

    UFUNCTION(BlueprintCallable)
    void GetBestHandShiftForObjectByConditions(EPRHandPoseType PoseType, UObject* Object, bool bLeft, const FTransform& CurrentHandTransform, bool bUseArmLengthLimit, const FVector& HandShoulderLocation, const UGripMotionControllerComponent* MotionController, bool& bSuccess, FTransform& PoseRelativeTransform, FTransform& PoseWorldTransform, EPRHandPoseGeometryType& PoseGeometryType, EPRHandPoseNumber& PoseNumber) const;

    UFUNCTION(BlueprintCallable)
    void GetBestHandShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, EPRHandPoseGeometryType& bestGeometryType, EPRHandPoseNumber& bestPoseNumber) const;

    UFUNCTION(BlueprintPure)
    static FPRCleanTransform FromTransform(FTransform Transform);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FShiftsPair MotionSourcesDefaultPosition;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<EPRControllerType, FShiftsPair> ControllerShifts;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float PistolsStickBreakDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* PrimaryHandPosesTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* PrimaryTriggeredHandPosesTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* PrimarySafetyHandPosesTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* SecondaryHandPosesTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* ThrowHandPosesTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* SlideHandPosesTable;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRHandPoseInfosPair HandsPoseDefault;
};
