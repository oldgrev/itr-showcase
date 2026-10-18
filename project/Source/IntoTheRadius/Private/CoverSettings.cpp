#include "CoverSettings.h"

#include "ITRDefaults.h"
FCoverSettings::FCoverSettings() {
    CoverPointMinDistance = {};
    SmallestAgentHeight = {};
    CoverPointGroundOffset = {};
    DistanceToCoverObject = {};
    ShootingPositionOffset = {};
    MinCoverWidth = {};
    OpenPointsGridCellSize = {};
    bAddCoversToFreePoints = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("CoverPointMinDistance"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SmallestAgentHeight"), (double)140);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CoverPointGroundOffset"), (double)10);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DistanceToCoverObject"), (double)80);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ShootingPositionOffset"), (double)20);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MinCoverWidth"), (double)150);
    ITRDefaults::Set(StaticStruct(), this, TEXT("OpenPointsGridCellSize"), (double)1000);
}
