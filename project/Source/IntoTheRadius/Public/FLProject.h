#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EPRHandPoseType.h"
#include "FLProject.generated.h"

class AActor;
class APawn;
class UGripMotionControllerComponent;
class UObject;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLProject : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLProject(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static FString TrimFloat(const float In, const int32 Digits);

    UFUNCTION(BlueprintPure)
    static FVector RoundVector(const FVector& In, const int32 Digits);

    UFUNCTION(BlueprintPure)
    static FTransform RoundTransform(const FTransform& In);

    UFUNCTION(BlueprintPure)
    static FRotator RoundRotator(const FRotator& In, const int32 Digits);

    UFUNCTION(BlueprintPure)
    static float RoundFloat(const float In, const int32 Digits);

    UFUNCTION(BlueprintPure)
    static float Negative(const float& In);

    UFUNCTION(BlueprintPure)
    TArray<UObject*> NativeSortObjectsByDistance(const TArray<UObject*> inArray, const AActor* DistanceFromActor);

    UFUNCTION(BlueprintPure)
    static bool IsInputEnabledAndNotSimulation();

    UFUNCTION(BlueprintPure)
    static bool GetSpawnPoint(const FVector& nearby, const float InRadius, const bool reachable, FVector& OutPoint);

    UFUNCTION(BlueprintPure)
    static bool GetReachablePointNotVisibleToPlayer(const APawn* PlayerPawn, const APawn* NPC, float MinDistFromPlayer, float SearchRadius, int32 NumAttempts, FVector& OutPoint);

    UFUNCTION(BlueprintPure)
    static bool GetNavigablePointBehindPlayer(const APawn* PlayerPawn, float MinDistFromPlayer, float SearchRadius, FVector& OutPoint);

    UFUNCTION(BlueprintCallable)
    static bool GetGripRelativeTransform(UObject* GripObject, UGripMotionControllerComponent* HandController, EPRHandPoseType PoseType, FTransform& OutGripRelativeTransform);

    UFUNCTION(BlueprintPure)
    static void GetGripObjectActor(UObject* Object, AActor*& Actor);

};
