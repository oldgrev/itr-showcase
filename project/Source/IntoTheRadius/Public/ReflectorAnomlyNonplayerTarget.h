#pragma once

#include "CoreMinimal.h"
#include "ReflectorAnomlyNonplayerTarget.generated.h"

class AActor;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FReflectorAnomlyNonplayerTarget {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* ActorRef;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector ActorLocation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector ShootLocation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector ActorVelocity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpinTime;
    FReflectorAnomlyNonplayerTarget();
};
