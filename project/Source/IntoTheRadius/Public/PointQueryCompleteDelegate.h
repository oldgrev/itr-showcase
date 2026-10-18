#pragma once

#include "CoreMinimal.h"
#include "NpcPointQueryResult.h"
#include "PointQueryCompleteDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FPointQueryCompleteDelegate, const FNpcPointQueryResult&, QueryResult);
