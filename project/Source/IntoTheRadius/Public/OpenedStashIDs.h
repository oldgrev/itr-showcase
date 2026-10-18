#pragma once

#include "CoreMinimal.h"
#include "OpenedStashIDs.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UOpenedStashIDs : public UObject {
    GENERATED_BODY()
public:
    UOpenedStashIDs(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly)
    TArray<FString> OpenedIDs;
};
