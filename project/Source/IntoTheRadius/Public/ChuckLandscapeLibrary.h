#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChuckLandscapeLibrary.generated.h"

class ALandscapeProxy;

// T-131 (cave stage 1, option A): Python access to the landscape visibility layer (holes): the Landscape Visibility Mask node of the showcase landscape material reads it. Editor only
// (the bodies are WITH_EDITOR; the cooked data carries the painted layer). Python: unreal.ChuckLandscape.set_visibility(landscape, polygon_world_cm, True)
UCLASS(meta = (ScriptName = "ChuckLandscape"))
class INTOTHERADIUS_API UChuckLandscapeLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** paint (bHidden = true) or clear the visibility layer over the polygon (world cm, XY used; landscape vertices inside it); returns the number of vertices written, negative on an error */
    UFUNCTION(BlueprintCallable, Category = "Chuck")
    static int32 SetVisibility(ALandscapeProxy* Landscape, const TArray<FVector>& WorldPolygon, bool bHidden);

    /** visibility layer value (0 visible .. 255 hidden) at the landscape vertex nearest to the world position; -1 when outside the landscape */
    UFUNCTION(BlueprintCallable, Category = "Chuck")
    static int32 ReadVisibility(ALandscapeProxy* Landscape, FVector WorldPosition);
};
