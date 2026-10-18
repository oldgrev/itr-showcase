// ITR Showcase: T-116 master rebuild helpers. See ItrShowcaseMasterLib.h.
#include "ItrShowcaseMasterLib.h"

#include "Materials/Material.h"
#include "Materials/MaterialExpression.h"

FString UItrShowcaseMasterLib::SetExpressionGuid(UMaterialExpression* Expression, const FString& Guid)
{
	if (!Expression) return TEXT("no expression");
	FGuid G;
	if (!FGuid::Parse(Guid, G)) return FString::Printf(TEXT("unparsable GUID '%s'"), *Guid);
	if (!Expression->bIsParameterExpression) return FString::Printf(TEXT("%s has no ExpressionGUID"), *Expression->GetName());
	Expression->Modify();
	Expression->GetParameterExpressionId() = G;
	return FString();
}

FString UItrShowcaseMasterLib::GetExpressionGuid(UMaterialExpression* Expression)
{
	if (!Expression || !Expression->bIsParameterExpression) return FString();
	return Expression->GetParameterExpressionId().ToString(EGuidFormats::UniqueObjectGuid);
}

FString UItrShowcaseMasterLib::ConnectMaterialAttributes(UMaterial* Material, UMaterialExpression* Expression, int32 OutputIndex)
{
	if (!Material || !Expression) return TEXT("no material or expression");
	if (!Expression->GetOutputs().IsValidIndex(OutputIndex)) return FString::Printf(TEXT("%s has no output %d"), *Expression->GetName(), OutputIndex);
	Material->Modify();
	Material->bUseMaterialAttributes = true;
	Expression->ConnectExpression(&Material->MaterialAttributes, OutputIndex);
	return FString();
}

FString UItrShowcaseMasterLib::SetMaterialInputMask(UMaterial* Material, int32 PropertyIndex, int32 Mask, int32 MaskR, int32 MaskG, int32 MaskB, int32 MaskA)
{
	if (!Material) return TEXT("no material");
	if (PropertyIndex < 0 || PropertyIndex >= MP_MAX) return FString::Printf(TEXT("bad property %d"), PropertyIndex);
	FExpressionInput* In = Material->GetExpressionInputForProperty((EMaterialProperty)PropertyIndex);
	if (!In) return FString::Printf(TEXT("material has no input %d"), PropertyIndex);
	if (!In->Expression) return FString::Printf(TEXT("input %d is not connected"), PropertyIndex);
	Material->Modify();
	In->Mask = Mask; In->MaskR = MaskR; In->MaskG = MaskG; In->MaskB = MaskB; In->MaskA = MaskA;
	return FString();
}
