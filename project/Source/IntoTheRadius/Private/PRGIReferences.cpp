#include "PRGIReferences.h"

UPRGIReferences::UPRGIReferences(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

UObject* UPRGIReferences::GetControllerReference(const TSubclassOf<UInterface> Interface) {
    return {};
}

