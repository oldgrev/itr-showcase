#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRNPCInfo.h"
#include "INPC.generated.h"

class AActor;
class UPrimitiveComponent;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UINPC : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IINPC {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetSnipingMode(const bool bSet);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetDebug(const bool NewDebug);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsCriticalHit(const UPrimitiveComponent* HitComponent, const FName BoneName) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsAttacksLocked() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsArmored() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FPRNPCInfo GetNPCInfo() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetIDs(FGameplayTag& TypeID, FString& InstanceId);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Alert(AActor* Target, FTransform Location);

};
