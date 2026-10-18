#pragma once

#include "CoreMinimal.h"
#include "ECharCommand.h"
#include "IBotController.generated.h"

class AActor;
class APRBasicActor;
class APawn;
class UPRNpcPerceptionComponent;

UINTERFACE(MinimalAPI, Blueprintable)
class UIBotController : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIBotController {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetTargetActor(AActor* Target);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetLeader(APRBasicActor* NewLeader);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetDesiredPosition(FVector Pos);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ReportEnemyLocation(FVector Loc);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void RemoveSquadMember(APawn* Pawn);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OrderCover();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OrderCompleted(APawn* Pawn);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OrderAttack();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    FVector GetTargetLocation();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    AActor* GetTargetActor();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    TArray<AActor*> GetSquadMembers();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UPRNpcPerceptionComponent* GetPerception();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    FVector GetDesiredPosition();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetCommand(ECharCommand& CurrentCommand);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void AddSquadMember(APawn* Pawn);

};
