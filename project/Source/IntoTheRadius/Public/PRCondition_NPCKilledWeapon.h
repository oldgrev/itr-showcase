#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition_NPC.h"
#include "PRCondition_NPCKilledWeapon.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_NPCKilledWeapon : public UPRCondition_NPC {
    GENERATED_BODY()
public:
    UPRCondition_NPCKilledWeapon(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag WeaponTypeID;
};
