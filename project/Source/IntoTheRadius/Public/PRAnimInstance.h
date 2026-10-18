#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PRAnimInstance.generated.h"

class AActor;
class USkeletalMeshComponent;

UCLASS(Blueprintable, BlueprintType, Within=SkeletalMeshComponent)
class INTOTHERADIUS_API UPRAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPRAnimInstance(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    USkeletalMeshComponent* GetSMC();

    UFUNCTION(BlueprintCallable)
    AActor* GetActor();

private:
    UPROPERTY()
    USkeletalMeshComponent* _smc;
    UPROPERTY()
    AActor* _actor;
};
