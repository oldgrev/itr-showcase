#pragma once

#include "CoreMinimal.h"
#include "EPRHandPoseGeometryType.h"
#include "EPRHandPoseNumber.h"
#include "GripOverlap.generated.h"

class UObject;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FGripOverlap {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* Object;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ImplementsInterface;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform ObjectTransform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool CanBeClimbed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UPrimitiveComponent* OverlapedPrimitive;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsDistanceGrip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform GripPoint;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsSlotGrip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UPrimitiveComponent* TriggerPrimitive;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform TriggerPoint;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform HandTransformWhenOverlap;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseGeometryType GeometryType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseNumber PoseNumer;
    FGripOverlap();
};
