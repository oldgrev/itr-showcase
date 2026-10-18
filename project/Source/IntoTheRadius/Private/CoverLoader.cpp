#include "CoverLoader.h"
#include "CoverDebugComponent.h"
#include "ITRDefaults.h"

ACoverLoader::ACoverLoader(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UCoverDebugComponent* Sub0 = Cast<UCoverDebugComponent>(GetDefaultSubobjectByName(TEXT("CoverDebugComponent")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UCoverDebugComponent>(TEXT("CoverDebugComponent"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("CoverDebugComponent"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bDebugDrawCoverPoints"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bDebugDrawShootingPositions"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bIsEditorOnly"), true);
    }
    ITRDefaults::Set(GetClass(), this, TEXT("CoverSettings.CoverPointMinDistance"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("CoverSettings.SmallestAgentHeight"), (double)140);
    ITRDefaults::Set(GetClass(), this, TEXT("CoverSettings.CoverPointGroundOffset"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("CoverSettings.DistanceToCoverObject"), (double)80);
    ITRDefaults::Set(GetClass(), this, TEXT("CoverSettings.ShootingPositionOffset"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("CoverSettings.MinCoverWidth"), (double)150);
    ITRDefaults::Set(GetClass(), this, TEXT("CoverSettings.OpenPointsGridCellSize"), (double)1000);
    ITRDefaults::SetObject(GetClass(), this, TEXT("DebugComponent"), GetDefaultSubobjectByName(TEXT("CoverDebugComponent")));
}

