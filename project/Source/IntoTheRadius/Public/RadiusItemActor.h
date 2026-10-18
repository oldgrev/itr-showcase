#pragma once

#include "CoreMinimal.h"
#include "GrippableStaticMeshActor.h"
#include "DamageDealerInterface.h"
#include "IPRItem.h"
#include "RadiusItemActor.generated.h"

class UPRCondition;
class UPrimitiveComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusItemActor : public AGrippableStaticMeshActor, public IIPRItem, public IDamageDealerInterface {
    GENERATED_BODY()
public:
    ARadiusItemActor(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> SpawnConditions;
protected:
    UPROPERTY(EditDefaultsOnly)
    UStaticMesh* ProxyModel;
    UPROPERTY(BlueprintReadOnly)
    TArray<UStaticMeshComponent*> OriginalModelCompList;
    UPROPERTY(BlueprintReadOnly)
    TArray<UPrimitiveComponent*> ProxyOmittableColliderList;
    UPROPERTY(BlueprintReadOnly)
    bool bCanAddToLevelInventory;
private:
    UPROPERTY()
    UStaticMeshComponent* ProxyComp;
};
