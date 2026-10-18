#include "PRAnimInstance.h"

UPRAnimInstance::UPRAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

USkeletalMeshComponent* UPRAnimInstance::GetSMC() {
    return {};
}

AActor* UPRAnimInstance::GetActor() {
    return {};
}

