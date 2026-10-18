#include "FLProject.h"

UFLProject::UFLProject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FString UFLProject::TrimFloat(const float In, const int32 Digits) {
    return {};
}

FVector UFLProject::RoundVector(const FVector& In, const int32 Digits) {
    return {};
}

FTransform UFLProject::RoundTransform(const FTransform& In) {
    return {};
}

FRotator UFLProject::RoundRotator(const FRotator& In, const int32 Digits) {
    return {};
}

float UFLProject::RoundFloat(const float In, const int32 Digits) {
    return {};
}

float UFLProject::Negative(const float& In) {
    return {};
}

TArray<UObject*> UFLProject::NativeSortObjectsByDistance(const TArray<UObject*> inArray, const AActor* DistanceFromActor) {
    return {};
}

bool UFLProject::IsInputEnabledAndNotSimulation() {
    return {};
}

bool UFLProject::GetSpawnPoint(const FVector& nearby, const float InRadius, const bool reachable, FVector& OutPoint) {
    return {};
}

bool UFLProject::GetReachablePointNotVisibleToPlayer(const APawn* PlayerPawn, const APawn* NPC, float MinDistFromPlayer, float SearchRadius, int32 NumAttempts, FVector& OutPoint) {
    return {};
}

bool UFLProject::GetNavigablePointBehindPlayer(const APawn* PlayerPawn, float MinDistFromPlayer, float SearchRadius, FVector& OutPoint) {
    return {};
}

bool UFLProject::GetGripRelativeTransform(UObject* GripObject, UGripMotionControllerComponent* HandController, EPRHandPoseType PoseType, FTransform& OutGripRelativeTransform) {
    return {};
}

void UFLProject::GetGripObjectActor(UObject* Object, AActor*& Actor) {
}

