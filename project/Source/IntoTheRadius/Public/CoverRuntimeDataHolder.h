#pragma once

#include "CoreMinimal.h"
#include "CoverRuntimeDataHolder.generated.h"

class AActor;
class UCoverRuntimeDataHolder;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UCoverRuntimeDataHolder : public UObject {
    GENERATED_BODY()
public:
    UCoverRuntimeDataHolder(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ToggleDebug();

    UFUNCTION()
    void OnLevelUnloaded();

    UFUNCTION(BlueprintCallable)
    bool GetDebugEnabled() const;

    UFUNCTION(BlueprintPure)
    static UCoverRuntimeDataHolder* GetCoverRuntimeDataHolder();

    UFUNCTION(BlueprintCallable)
    void DrawShippingDebug(const UObject* WorldContextObject, const FVector CurrentLocation, float Radius);

    UFUNCTION(BlueprintCallable)
    void DebugDraw(const UObject* WorldContextObject);

    UPROPERTY()
    TSubclassOf<AActor> ShippingDebugActor;
};
