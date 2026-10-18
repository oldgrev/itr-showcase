#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "IInstanceID.h"
#include "SpawnSlotComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API USpawnSlotComponent : public UBoxComponent, public IIInstanceID {
    GENERATED_BODY()
public:
    USpawnSlotComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void MarkSocketMatch(const TArray<FName> SocketNames, const FColor Color);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlotId;
};
