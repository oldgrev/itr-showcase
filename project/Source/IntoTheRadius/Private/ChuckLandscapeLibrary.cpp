#include "ChuckLandscapeLibrary.h"
#include "Landscape.h"
#include "LandscapeProxy.h"
#include "LandscapeInfo.h"
#include "LandscapeComponent.h"
#include "LandscapeEdit.h"

#if WITH_EDITOR
static bool ChuckInPoly(const TArray<FVector2D>& P, float X, float Y)
{
    bool In = false;
    for (int32 i = 0, j = P.Num() - 1; i < P.Num(); j = i++)
    {
        if (((P[i].Y > Y) != (P[j].Y > Y)) && (X < (P[j].X - P[i].X) * (Y - P[i].Y) / (P[j].Y - P[i].Y) + P[i].X))
        {
            In = !In;
        }
    }
    return In;
}
#endif

int32 UChuckLandscapeLibrary::SetVisibility(ALandscapeProxy* Landscape, const TArray<FVector>& WorldPolygon, bool bHidden)
{
#if WITH_EDITOR
    if (!Landscape || WorldPolygon.Num() < 3)
    {
        return -1;
    }
    ULandscapeInfo* Info = Landscape->GetLandscapeInfo();
    if (!Info)
    {
        return -2;
    }
    const FTransform LT = Landscape->GetActorTransform();
    TArray<FVector2D> Local;
    float MinX = 1e30f, MinY = 1e30f, MaxX = -1e30f, MaxY = -1e30f;
    for (const FVector& W : WorldPolygon)
    {
        const FVector L = LT.InverseTransformPosition(W);
        Local.Add(FVector2D(L.X, L.Y));
        MinX = FMath::Min(MinX, L.X); MaxX = FMath::Max(MaxX, L.X);
        MinY = FMath::Min(MinY, L.Y); MaxY = FMath::Max(MaxY, L.Y);
    }
    int32 LX1, LY1, LX2, LY2;
    if (!Info->GetLandscapeExtent(LX1, LY1, LX2, LY2))
    {
        return -3;
    }
    const int32 X1 = FMath::Max(LX1, FMath::FloorToInt(MinX)), Y1 = FMath::Max(LY1, FMath::FloorToInt(MinY));
    const int32 X2 = FMath::Min(LX2, FMath::CeilToInt(MaxX)), Y2 = FMath::Min(LY2, FMath::CeilToInt(MaxY));
    if (X2 < X1 || Y2 < Y1)
    {
        return -4;
    }
    FLandscapeEditDataInterface Edit(Info);
    const int32 W = X2 - X1 + 1, H = Y2 - Y1 + 1;
    TArray<uint8> Data;
    Data.SetNumZeroed(W * H);
    Edit.GetWeightDataFast(ALandscapeProxy::VisibilityLayer, X1, Y1, X2, Y2, Data.GetData(), 0);     // keep what is painted already
    int32 N = 0;
    for (int32 y = Y1; y <= Y2; ++y)
    {
        for (int32 x = X1; x <= X2; ++x)
        {
            if (ChuckInPoly(Local, (float)x, (float)y))
            {
                Data[(y - Y1) * W + (x - X1)] = bHidden ? 255 : 0;
                ++N;
            }
        }
    }
    Edit.SetAlphaData(ALandscapeProxy::VisibilityLayer, X1, Y1, X2, Y2, Data.GetData(), 0, ELandscapeLayerPaintingRestriction::None, true, false);
    Edit.Flush();
    return N;
#else
    return -9;
#endif
}

int32 UChuckLandscapeLibrary::ReadVisibility(ALandscapeProxy* Landscape, FVector WorldPosition)
{
#if WITH_EDITOR
    if (!Landscape)
    {
        return -1;
    }
    ULandscapeInfo* Info = Landscape->GetLandscapeInfo();
    if (!Info)
    {
        return -2;
    }
    const FVector L = Landscape->GetActorTransform().InverseTransformPosition(WorldPosition);
    const int32 X = FMath::RoundToInt(L.X), Y = FMath::RoundToInt(L.Y);
    int32 LX1, LY1, LX2, LY2;
    if (!Info->GetLandscapeExtent(LX1, LY1, LX2, LY2) || X < LX1 || X > LX2 || Y < LY1 || Y > LY2)
    {
        return -1;
    }
    FLandscapeEditDataInterface Edit(Info);
    uint8 V = 0;
    int32 X1 = X, Y1 = Y, X2 = X, Y2 = Y;
    Edit.GetWeightDataFast(ALandscapeProxy::VisibilityLayer, X1, Y1, X2, Y2, &V, 0);
    return (int32)V;
#else
    return -9;
#endif
}
