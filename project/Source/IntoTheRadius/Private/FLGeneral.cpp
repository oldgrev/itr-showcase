#include "FLGeneral.h"

UFLGeneral::UFLGeneral(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FText UFLGeneral::TracersShowTypeToText(const ETracersShowType TracersShowType) {
    return {};
}

FString UFLGeneral::TracersShowTypeToString(const ETracersShowType TracersShowType) {
    return {};
}

FString UFLGeneral::TagsArrayAsString(const FString& Prefix, TArray<FGameplayTag> tagsArray) {
    return {};
}

AActor* UFLGeneral::SpawnActorWithLabel(const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass, const FVector& Location, const FString& Label) {
    return {};
}

void UFLGeneral::SortComponentsByLabel(TArray<USceneComponent*> In, TArray<USceneComponent*>& Out) {
}

void UFLGeneral::ShowMessage(const FString& Message, const FString& Title) {
}

FTransform UFLGeneral::ShiftActorByComponent(const AActor* Actor, const USceneComponent* Component, const FTransform& TargetTransform) {
    return {};
}

void UFLGeneral::SetLightVisibility(ULightComponent* Light, bool IsVisible) {
}

void UFLGeneral::SetLightAffectsWorld(ULightComponent* Component, bool bAffects) {
}

void UFLGeneral::SetCanEverAffectNavigation(UActorComponent* Component, bool bRelevant) {
}

void UFLGeneral::SetAngularRotationOffset(UPhysicsConstraintComponent* Component, const FRotator RotationOffset) {
}

void UFLGeneral::SetActorSimulatePhysics(const AActor* Actor, bool Simulate, bool zeroVel, bool& success, UPrimitiveComponent*& Primitive) {
}

bool UFLGeneral::SetActorEnableGravity(const AActor* Actor, bool enable) {
    return {};
}

void UFLGeneral::SafeDestroyActor(AActor* Actor) {
}

FGameplayTagContainer UFLGeneral::RequestGameplayTagChildren(const TArray<FGameplayTag>& GameplayTags) {
    return {};
}

void UFLGeneral::RefreshHolders(UObject* Object) {
}

void UFLGeneral::PutActorInPersistentLevel(AActor* Actor) {
}

float UFLGeneral::ProtectedApplyPointDamage(AActor* DamagedActor, float BaseDamage, const FVector& HitFromDirection, const FHitResult& HitInfo, AActor* ActorInstigator, AActor* DamageCauser, TSubclassOf<UDamageType> DamageTypeClass) {
    return {};
}

void UFLGeneral::PrintObjectReferences(UObject* Object) {
}

FRadiusGameDifficulty UFLGeneral::PresetToDifficulty(const EPRGameDifficultyPreset DifficultyPreset) {
    return {};
}

bool UFLGeneral::ParseCommandLine(const FString ParameterName, FString& Value) {
    return {};
}

FMinMaxFloat UFLGeneral::Multiply_MinMaxFloat(FMinMaxFloat A, const float B) {
    return {};
}

void UFLGeneral::KillActorWithChildren(AActor* Actor) {
}

void UFLGeneral::KillActorsByClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorsClass, bool bWithChildren) {
}

void UFLGeneral::KillActor(AActor* Actor) {
}

FText UFLGeneral::ItemsDropTypeToText(const EItemsDropType DropType) {
    return {};
}

FString UFLGeneral::ItemsDropTypeToString(const EItemsDropType DropType) {
    return {};
}

bool UFLGeneral::IsZeroParallelepiped(FParallelepiped Rect) {
    return {};
}

bool UFLGeneral::IsZeroInt(FMinMaxInt MinMax) {
    return {};
}

bool UFLGeneral::IsZeroFloat(FMinMaxFloat MinMax) {
    return {};
}

bool UFLGeneral::IsZeroDiffInt(FMinMaxInt MinMax) {
    return {};
}

bool UFLGeneral::IsZeroDiffFloat(FMinMaxFloat MinMax) {
    return {};
}

bool UFLGeneral::IsProfilingInCommandLine() {
    return {};
}

bool UFLGeneral::IsPreviewActor(const AActor* Actor) {
    return {};
}

bool UFLGeneral::IsPassedTutorialUnseen(FGameplayTag TriggerTag) {
    return {};
}

bool UFLGeneral::IsParallelepipedIntersectSphere(const FParallelepiped Rect, const FVector SphereCenter, const float SphereRadius) {
    return {};
}

bool UFLGeneral::IsParallelepipedIntersectPoint(const FParallelepiped Rect, const FVector Point) {
    return {};
}

bool UFLGeneral::IsNecessaryTutorial() {
    return {};
}

bool UFLGeneral::IsInTutorialLevel() {
    return {};
}

bool UFLGeneral::IsInMainMenuLevel() {
    return {};
}

bool UFLGeneral::IsInBoundsIgnoreZ(const FVector& Point, const FTransform& BoxWorldTransform, const FVector& BoxExtent) {
    return {};
}

bool UFLGeneral::IsGameStarted() {
    return {};
}

bool UFLGeneral::IsGameRunning(const UObject* WorldContextObject) {
    return {};
}

bool UFLGeneral::IsGameplayRunning() {
    return {};
}

bool UFLGeneral::IsGameClosing() {
    return {};
}

bool UFLGeneral::IsFreeGame() {
    return {};
}

bool UFLGeneral::IsEditorCustomStartup() {
    return {};
}

bool UFLGeneral::IsEarlyAccessPlayer() {
    return {};
}

bool UFLGeneral::IsDifficultyChanged(const FRadiusGameDifficulty NewDifficulty) {
    return {};
}

bool UFLGeneral::IsDifficultyAppliedAfterTide(const FRadiusGameDifficulty NewDifficulty) {
    return {};
}

bool UFLGeneral::IsDefaultUpgrade(const FGameplayTag UpgradeID, UInventoryItem* Item) {
    return {};
}

bool UFLGeneral::IsCorpsesCensored() {
    return {};
}

bool UFLGeneral::IsConditionsPassed(const TArray<UPRCondition*> Conditions) {
    return {};
}

bool UFLGeneral::IsComponentBoundsIntersect(const UPrimitiveComponent* ComponentA, const UPrimitiveComponent* ComponentB) {
    return {};
}

bool UFLGeneral::IsCommandLine(const FString ParameterName) {
    return {};
}

bool UFLGeneral::IsActorInLevel(const AActor* Actor, const FGameplayTag LevelTag) {
    return {};
}

bool UFLGeneral::IsActorInCurrentLevel(const AActor* Actor) {
    return {};
}

bool UFLGeneral::HasUnseenPassedTutorials() {
    return {};
}

bool UFLGeneral::HasPassedTutorials() {
    return {};
}

float UFLGeneral::GetTrueMin(FMinMaxFloat MinMax) {
    return {};
}

float UFLGeneral::GetTrueMax(FMinMaxFloat MinMax) {
    return {};
}

void UFLGeneral::GetTimeStringFromSeconds(int32 TotalSeconds, bool bNoSeconds, FString& String) {
}

void UFLGeneral::GetTimeSpentString(int32 TotalMinutes, FString& String) {
}

FName UFLGeneral::GetStreamingLevelNameFromActor(const AActor* Actor) {
    return {};
}

float UFLGeneral::GetSignedAngle(FVector Normal, FVector v1, FVector v2) {
    return {};
}

FTransform UFLGeneral::GetRelativeTransform(const AActor* Actor) {
    return {};
}

int32 UFLGeneral::GetRandomInt(FMinMaxInt MinMax) {
    return {};
}

float UFLGeneral::GetRandomFloat(FMinMaxFloat MinMax) {
    return {};
}

void UFLGeneral::GetPRPlayerPawn(const UObject* WorldContextObject, APawn*& PRPlayerPawn) {
}

FVector UFLGeneral::GetPointsBoxSize(const TArray<FVector> Points) {
    return {};
}

UClass* UFLGeneral::GetParentClass(UClass* Class) {
    return {};
}

UClass* UFLGeneral::GetObjectParentClass(UObject* Object) {
    return {};
}

FName UFLGeneral::GetObjectFName(const UObject* Object) {
    return {};
}

FString UFLGeneral::GetNewNoteMarker(const FGameplayTag& Tag) {
    return {};
}

FTutorialConfig UFLGeneral::GetNecessaryTutorialConfig() {
    return {};
}

void UFLGeneral::GetMapLevelTag(const UObject* WorldContextObject, FGameplayTag& LevelTag) {
}

void UFLGeneral::GetLevelByName(const FString& LevelName, FGameplayTag& LevelTag) {
}

FBox UFLGeneral::GetLevelBounds(ULevel* TargetLevel, FVector& LevelLocation) {
    return {};
}

bool UFLGeneral::GetGamePurchaseDate(FDateTime& PurchaseDate, FString& PurchaseDateString) {
    return {};
}

void UFLGeneral::GetDateTimeString(FDateTime DateTime, FString& String) {
}

UObject* UFLGeneral::GetAttackFromPawn(APawn* Pawn) {
    return {};
}

TArray<FGameplayTag> UFLGeneral::GetAllSecondaryWeaponTags() {
    return {};
}

TArray<FGameplayTag> UFLGeneral::GetAllPrimaryWeaponTags() {
    return {};
}

TArray<FGameplayTag> UFLGeneral::GetAllCassetteTags() {
    return {};
}

TArray<FGameplayTag> UFLGeneral::GetAllArtifactTags() {
    return {};
}

FGameplayTag UFLGeneral::GetActorLevelTag(const AActor* Actor) {
    return {};
}

FString UFLGeneral::GetActorLevelName(const AActor* Actor) {
    return {};
}

void UFLGeneral::GetActorHolderTransform(const AActor* Actor, const FGameplayTag HolderID, bool& success, FTransform& RelativeTransform) {
}

FString UFLGeneral::GameDefaultMap() {
    return {};
}

int32 UFLGeneral::FindIndexOfTag(const FGameplayTag& Tag, const TArray<FGameplayTag>& Array, bool bExact) {
    return {};
}

float UFLGeneral::FindDistanceAlongSplineClosestToLocation(const USplineComponent* Spline, const FVector& Location) {
    return {};
}

void UFLGeneral::DrawArrow(const UObject* WorldContextObject, const FVector LineStart, const FVector LineEnd, const float ArrowSize, const FLinearColor Color, const float Duration, const float Thickness) {
}

FText UFLGeneral::DifficultyTypeToText(const EDifficultyType DifficultyType) {
    return {};
}

FString UFLGeneral::DifficultyTypeToString(const EDifficultyType DifficultyType) {
    return {};
}

EPRGameDifficultyPreset UFLGeneral::DifficultyToPreset(const FRadiusGameDifficulty GameDifficulty) {
    return {};
}

FText UFLGeneral::DifficultyPresetToText(const EPRGameDifficultyPreset DifficultyPreset) {
    return {};
}

FString UFLGeneral::DifficultyPresetToString(const EPRGameDifficultyPreset DifficultyPreset) {
    return {};
}

void UFLGeneral::DifficultiesToNames(TArray<EDifficultyType> Difficulties, TArray<FText>& Names, TArray<int32>& Indexes) {
}

void UFLGeneral::ClearUnseenPassedTutorials() {
}

void UFLGeneral::CheckUniqueInstanceID(const UObject* WorldContextObject, UPARAM(ref) FString& UID, const FString Prefix, const bool bOnlyIfEmpty) {
}

FVector UFLGeneral::CalcLocalBounds(USceneComponent* Component) {
    return {};
}

bool UFLGeneral::BlinkFloorSweepTest(UCharacterMovementComponent* MovementComponent, ACharacter* CharacterOwner, FHitResult& Hit, const FVector& CapsuleLocation, const FVector& TraceStart, const FVector& TraceEnd) {
    return {};
}

TArray<FGameplayTag> UFLGeneral::AsArray(const FGameplayTagContainer& Container) {
    return {};
}

FPRNPCInfo UFLGeneral::ApplyDifficultyModifiers(FPRNPCInfo NpcInfo) {
    return {};
}

FString UFLGeneral::AmmoContainerDataAsString(const FString& Prefix, FAmmoContainerData AmmoContainerData) {
    return {};
}

UActorComponent* UFLGeneral::AddComponentToActor(AActor* BaseActor, TSubclassOf<UActorComponent> AttachedComponent) {
    return {};
}

