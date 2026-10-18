#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AmmoContainerData.h"
#include "EDifficultyType.h"
#include "EItemsDropType.h"
#include "EPRGameDifficultyPreset.h"
#include "ETracersShowType.h"
#include "MinMaxFloat.h"
#include "MinMaxInt.h"
#include "PRNPCInfo.h"
#include "Parallelepiped.h"
#include "RadiusGameDifficulty.h"
#include "TutorialConfig.h"
#include "FLGeneral.generated.h"

class AActor;
class ACharacter;
class APawn;
class UActorComponent;
class UCharacterMovementComponent;
class UDamageType;
class UInventoryItem;
class ULevel;
class ULightComponent;
class UObject;
class UPRCondition;
class UPhysicsConstraintComponent;
class UPrimitiveComponent;
class USceneComponent;
class USplineComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLGeneral : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLGeneral(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static FText TracersShowTypeToText(const ETracersShowType TracersShowType);

    UFUNCTION(BlueprintPure)
    static FString TracersShowTypeToString(const ETracersShowType TracersShowType);

    UFUNCTION(BlueprintPure)
    static FString TagsArrayAsString(const FString& Prefix, TArray<FGameplayTag> tagsArray);

    UFUNCTION(BlueprintCallable)
    static AActor* SpawnActorWithLabel(const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass, const FVector& Location, const FString& Label);

    UFUNCTION(BlueprintPure)
    static void SortComponentsByLabel(TArray<USceneComponent*> In, TArray<USceneComponent*>& Out);

    UFUNCTION(BlueprintCallable)
    static void ShowMessage(const FString& Message, const FString& Title);

    UFUNCTION(BlueprintPure)
    static FTransform ShiftActorByComponent(const AActor* Actor, const USceneComponent* Component, const FTransform& TargetTransform);

    UFUNCTION(BlueprintCallable)
    static void SetLightVisibility(ULightComponent* Light, bool IsVisible);

    UFUNCTION(BlueprintCallable)
    static void SetLightAffectsWorld(ULightComponent* Component, bool bAffects);

    UFUNCTION(BlueprintCallable)
    static void SetCanEverAffectNavigation(UActorComponent* Component, bool bRelevant);

    UFUNCTION(BlueprintCallable)
    static void SetAngularRotationOffset(UPhysicsConstraintComponent* Component, const FRotator RotationOffset);

    UFUNCTION(BlueprintCallable)
    static void SetActorSimulatePhysics(const AActor* Actor, bool Simulate, bool zeroVel, bool& success, UPrimitiveComponent*& Primitive);

    UFUNCTION(BlueprintCallable)
    static bool SetActorEnableGravity(const AActor* Actor, bool enable);

    UFUNCTION(BlueprintCallable)
    static void SafeDestroyActor(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    static FGameplayTagContainer RequestGameplayTagChildren(const TArray<FGameplayTag>& GameplayTags);

    UFUNCTION(BlueprintCallable)
    static void RefreshHolders(UObject* Object);

    UFUNCTION(BlueprintCallable)
    static void PutActorInPersistentLevel(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    static float ProtectedApplyPointDamage(AActor* DamagedActor, float BaseDamage, const FVector& HitFromDirection, const FHitResult& HitInfo, AActor* ActorInstigator, AActor* DamageCauser, TSubclassOf<UDamageType> DamageTypeClass);

    UFUNCTION(BlueprintCallable)
    static void PrintObjectReferences(UObject* Object);

    UFUNCTION(BlueprintPure)
    static FRadiusGameDifficulty PresetToDifficulty(const EPRGameDifficultyPreset DifficultyPreset);

    UFUNCTION(BlueprintPure)
    static bool ParseCommandLine(const FString ParameterName, FString& Value);

    UFUNCTION(BlueprintPure)
    static FMinMaxFloat Multiply_MinMaxFloat(FMinMaxFloat A, const float B);

    UFUNCTION(BlueprintCallable)
    static void KillActorWithChildren(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    static void KillActorsByClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorsClass, bool bWithChildren);

    UFUNCTION(BlueprintCallable)
    static void KillActor(AActor* Actor);

    UFUNCTION(BlueprintPure)
    static FText ItemsDropTypeToText(const EItemsDropType DropType);

    UFUNCTION(BlueprintPure)
    static FString ItemsDropTypeToString(const EItemsDropType DropType);

    UFUNCTION(BlueprintPure)
    static bool IsZeroParallelepiped(FParallelepiped Rect);

    UFUNCTION(BlueprintPure)
    static bool IsZeroInt(FMinMaxInt MinMax);

    UFUNCTION(BlueprintPure)
    static bool IsZeroFloat(FMinMaxFloat MinMax);

    UFUNCTION(BlueprintPure)
    static bool IsZeroDiffInt(FMinMaxInt MinMax);

    UFUNCTION(BlueprintPure)
    static bool IsZeroDiffFloat(FMinMaxFloat MinMax);

    UFUNCTION(BlueprintPure)
    static bool IsProfilingInCommandLine();

    UFUNCTION(BlueprintPure)
    static bool IsPreviewActor(const AActor* Actor);

    UFUNCTION(BlueprintPure)
    static bool IsPassedTutorialUnseen(FGameplayTag TriggerTag);

    UFUNCTION(BlueprintPure)
    static bool IsParallelepipedIntersectSphere(const FParallelepiped Rect, const FVector SphereCenter, const float SphereRadius);

    UFUNCTION(BlueprintPure)
    static bool IsParallelepipedIntersectPoint(const FParallelepiped Rect, const FVector Point);

    UFUNCTION(BlueprintPure)
    static bool IsNecessaryTutorial();

    UFUNCTION(BlueprintPure)
    static bool IsInTutorialLevel();

    UFUNCTION(BlueprintPure)
    static bool IsInMainMenuLevel();

    UFUNCTION(BlueprintPure)
    static bool IsInBoundsIgnoreZ(const FVector& Point, const FTransform& BoxWorldTransform, const FVector& BoxExtent);

    UFUNCTION(BlueprintPure)
    static bool IsGameStarted();

    UFUNCTION(BlueprintPure)
    static bool IsGameRunning(const UObject* WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsGameplayRunning();

    UFUNCTION(BlueprintPure)
    static bool IsGameClosing();

    UFUNCTION(BlueprintPure)
    static bool IsFreeGame();

    UFUNCTION(BlueprintPure)
    static bool IsEditorCustomStartup();

    UFUNCTION(BlueprintPure)
    static bool IsEarlyAccessPlayer();

    UFUNCTION(BlueprintPure)
    static bool IsDifficultyChanged(const FRadiusGameDifficulty NewDifficulty);

    UFUNCTION(BlueprintPure)
    static bool IsDifficultyAppliedAfterTide(const FRadiusGameDifficulty NewDifficulty);

    UFUNCTION(BlueprintPure)
    static bool IsDefaultUpgrade(const FGameplayTag UpgradeID, UInventoryItem* Item);

    UFUNCTION(BlueprintPure)
    static bool IsCorpsesCensored();

    UFUNCTION(BlueprintPure)
    static bool IsConditionsPassed(const TArray<UPRCondition*> Conditions);

    UFUNCTION(BlueprintPure)
    static bool IsComponentBoundsIntersect(const UPrimitiveComponent* ComponentA, const UPrimitiveComponent* ComponentB);

    UFUNCTION(BlueprintPure)
    static bool IsCommandLine(const FString ParameterName);

    UFUNCTION(BlueprintPure)
    static bool IsActorInLevel(const AActor* Actor, const FGameplayTag LevelTag);

    UFUNCTION(BlueprintPure)
    static bool IsActorInCurrentLevel(const AActor* Actor);

    UFUNCTION(BlueprintPure)
    static bool HasUnseenPassedTutorials();

    UFUNCTION(BlueprintPure)
    static bool HasPassedTutorials();

    UFUNCTION(BlueprintPure)
    static float GetTrueMin(FMinMaxFloat MinMax);

    UFUNCTION(BlueprintPure)
    static float GetTrueMax(FMinMaxFloat MinMax);

    UFUNCTION(BlueprintPure)
    static void GetTimeStringFromSeconds(int32 TotalSeconds, bool bNoSeconds, FString& String);

    UFUNCTION(BlueprintPure)
    static void GetTimeSpentString(int32 TotalMinutes, FString& String);

    UFUNCTION(BlueprintPure)
    static FName GetStreamingLevelNameFromActor(const AActor* Actor);

    UFUNCTION(BlueprintPure)
    static float GetSignedAngle(FVector Normal, FVector v1, FVector v2);

    UFUNCTION(BlueprintPure)
    static FTransform GetRelativeTransform(const AActor* Actor);

    UFUNCTION(BlueprintPure)
    static int32 GetRandomInt(FMinMaxInt MinMax);

    UFUNCTION(BlueprintPure)
    static float GetRandomFloat(FMinMaxFloat MinMax);

    UFUNCTION(BlueprintPure)
    static void GetPRPlayerPawn(const UObject* WorldContextObject, APawn*& PRPlayerPawn);

    UFUNCTION(BlueprintPure)
    static FVector GetPointsBoxSize(const TArray<FVector> Points);

    UFUNCTION(BlueprintPure)
    static UClass* GetParentClass(UClass* Class);

    UFUNCTION(BlueprintPure)
    static UClass* GetObjectParentClass(UObject* Object);

    UFUNCTION(BlueprintPure)
    static FName GetObjectFName(const UObject* Object);

    UFUNCTION(BlueprintPure)
    static FString GetNewNoteMarker(const FGameplayTag& Tag);

    UFUNCTION(BlueprintPure)
    static FTutorialConfig GetNecessaryTutorialConfig();

    UFUNCTION(BlueprintPure)
    static void GetMapLevelTag(const UObject* WorldContextObject, FGameplayTag& LevelTag);

    UFUNCTION(BlueprintPure)
    static void GetLevelByName(const FString& LevelName, FGameplayTag& LevelTag);

    UFUNCTION(BlueprintCallable)
    static FBox GetLevelBounds(ULevel* TargetLevel, FVector& LevelLocation);

    UFUNCTION(BlueprintPure)
    static bool GetGamePurchaseDate(FDateTime& PurchaseDate, FString& PurchaseDateString);

    UFUNCTION(BlueprintPure)
    static void GetDateTimeString(FDateTime DateTime, FString& String);

    UFUNCTION(BlueprintCallable)
    static UObject* GetAttackFromPawn(APawn* Pawn);

    UFUNCTION(BlueprintPure)
    static TArray<FGameplayTag> GetAllSecondaryWeaponTags();

    UFUNCTION(BlueprintPure)
    static TArray<FGameplayTag> GetAllPrimaryWeaponTags();

    UFUNCTION(BlueprintPure)
    static TArray<FGameplayTag> GetAllCassetteTags();

    UFUNCTION(BlueprintPure)
    static TArray<FGameplayTag> GetAllArtifactTags();

    UFUNCTION(BlueprintPure)
    static FGameplayTag GetActorLevelTag(const AActor* Actor);

    UFUNCTION(BlueprintPure)
    static FString GetActorLevelName(const AActor* Actor);

    UFUNCTION(BlueprintCallable)
    static void GetActorHolderTransform(const AActor* Actor, const FGameplayTag HolderID, bool& success, FTransform& RelativeTransform);

    UFUNCTION(BlueprintPure)
    static FString GameDefaultMap();

    UFUNCTION(BlueprintPure)
    static int32 FindIndexOfTag(const FGameplayTag& Tag, const TArray<FGameplayTag>& Array, bool bExact);

    UFUNCTION(BlueprintPure)
    static float FindDistanceAlongSplineClosestToLocation(const USplineComponent* Spline, const FVector& Location);

    UFUNCTION(BlueprintCallable)
    static void DrawArrow(const UObject* WorldContextObject, const FVector LineStart, const FVector LineEnd, const float ArrowSize, const FLinearColor Color, const float Duration, const float Thickness);

    UFUNCTION(BlueprintPure)
    static FText DifficultyTypeToText(const EDifficultyType DifficultyType);

    UFUNCTION(BlueprintPure)
    static FString DifficultyTypeToString(const EDifficultyType DifficultyType);

    UFUNCTION(BlueprintPure)
    static EPRGameDifficultyPreset DifficultyToPreset(const FRadiusGameDifficulty GameDifficulty);

    UFUNCTION(BlueprintPure)
    static FText DifficultyPresetToText(const EPRGameDifficultyPreset DifficultyPreset);

    UFUNCTION(BlueprintPure)
    static FString DifficultyPresetToString(const EPRGameDifficultyPreset DifficultyPreset);

    UFUNCTION(BlueprintPure)
    static void DifficultiesToNames(TArray<EDifficultyType> Difficulties, TArray<FText>& Names, TArray<int32>& Indexes);

    UFUNCTION(BlueprintCallable)
    static void ClearUnseenPassedTutorials();

    UFUNCTION(BlueprintCallable)
    static void CheckUniqueInstanceID(const UObject* WorldContextObject, UPARAM(ref) FString& UID, const FString Prefix, const bool bOnlyIfEmpty);

    UFUNCTION(BlueprintPure)
    static FVector CalcLocalBounds(USceneComponent* Component);

    UFUNCTION(BlueprintPure)
    static bool BlinkFloorSweepTest(UCharacterMovementComponent* MovementComponent, ACharacter* CharacterOwner, FHitResult& Hit, const FVector& CapsuleLocation, const FVector& TraceStart, const FVector& TraceEnd);

    UFUNCTION(BlueprintPure)
    static TArray<FGameplayTag> AsArray(const FGameplayTagContainer& Container);

    UFUNCTION(BlueprintPure)
    static FPRNPCInfo ApplyDifficultyModifiers(FPRNPCInfo NpcInfo);

    UFUNCTION(BlueprintPure)
    static FString AmmoContainerDataAsString(const FString& Prefix, FAmmoContainerData AmmoContainerData);

    UFUNCTION(BlueprintCallable)
    static UActorComponent* AddComponentToActor(AActor* BaseActor, TSubclassOf<UActorComponent> AttachedComponent);

};
