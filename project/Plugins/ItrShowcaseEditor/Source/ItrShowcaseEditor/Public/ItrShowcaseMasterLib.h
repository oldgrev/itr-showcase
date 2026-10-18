// ITR Showcase: T-116 master rebuild helpers (editor-only) for tools/itr-showcase/audit/masters/_mlib.py.
// Python: unreal.ItrShowcaseMasterLib.<function>. Separate from ItrShowcaseAudit so master workers don't edit that file.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItrShowcaseMasterLib.generated.h"

class UMaterial;
class UMaterialExpression;

UCLASS()
class ITRSHOWCASEEDITOR_API UItrShowcaseMasterLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/** Sets a parameter expression's ExpressionGUID (not Python-visible) to the game's, given as "XXXXXXXX-XXXXXXXX-XXXXXXXX-XXXXXXXX"
	 *  (or any format FGuid::Parse accepts). The MIs' parameter values carry their master's ExpressionGUIDs. Returns "" or the problem. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Masters")
	static FString SetExpressionGuid(UMaterialExpression* Expression, const FString& Guid);

	/** The expression's ExpressionGUID as "XXXXXXXX-XXXXXXXX-XXXXXXXX-XXXXXXXX" ("" when it has none). */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Masters")
	static FString GetExpressionGuid(UMaterialExpression* Expression);

	/** Connects Expression's output OutputIndex to the material's MaterialAttributes input (bUseMaterialAttributes; MP_MaterialAttributes
	 *  is hidden from Python's MaterialProperty enum). Returns "" or the problem. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Masters")
	static FString ConnectMaterialAttributes(UMaterial* Material, UMaterialExpression* Expression, int32 OutputIndex);

	/** Sets the component mask of a connected material input (PropertyIndex = EMaterialProperty value). Connect() copies the output's
	 *  mask; game masters can carry other masks (e.g. RGB on a BreakMaterialAttributes 'Metallic' link from an older engine), which the
	 *  translator applies as a ComponentMask (on a uniform scalar: a '.xxx' slot). Mask 0 = none. Returns "" or the problem. */
	UFUNCTION(BlueprintCallable, Category = "ITR Showcase|Masters")
	static FString SetMaterialInputMask(UMaterial* Material, int32 PropertyIndex, int32 Mask, int32 MaskR, int32 MaskG, int32 MaskB, int32 MaskA);
};
