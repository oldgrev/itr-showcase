#pragma once

#include "CoreMinimal.h"
#include "ENpcPointQueryType.h"
#include "IClearable.h"
#include "NpcPointQueryHandle.h"
#include "NpcPointQueryParam.h"
#include "PointQueryCompleteDelegate.h"
#include "NpcPointQueryManager.generated.h"

class UNpcPointQueryManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UNpcPointQueryManager : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UNpcPointQueryManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static UNpcPointQueryManager* GetNpcPointQueryManager();

    UFUNCTION(BlueprintCallable)
    FNpcPointQueryHandle FindShootingPoint(const FNpcPointQueryParam& Param, FPointQueryCompleteDelegate FinishCallback, ENpcPointQueryType QueryType);

    UFUNCTION(BlueprintCallable)
    FNpcPointQueryHandle FindCoverPoint(const FNpcPointQueryParam& Param, FPointQueryCompleteDelegate FinishCallback);

    UFUNCTION(BlueprintCallable)
    void CancelQuery(UPARAM(ref) FNpcPointQueryHandle& Handle);

};
