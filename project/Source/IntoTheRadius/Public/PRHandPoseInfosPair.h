#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "EPRHandPoseGeometryType.h"
#include "EPRHandPoseNumber.h"
#include "EPRHandPoseSaveType.h"
#include "PRHandPoseInfo.h"
#include "PRHandPoseInfosPair.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRHandPoseInfosPair : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseSaveType SaveType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseNumber PoseNumber;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseGeometryType GeometryType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag PoseTag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StaticMeshComponentPath;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName StaticMeshComponentName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRHandPoseInfo Left;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRHandPoseInfo Right;
    FPRHandPoseInfosPair();
    ~FPRHandPoseInfosPair();
};
