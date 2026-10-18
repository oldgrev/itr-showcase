#pragma once

#include "CoreMinimal.h"
#include "OneParamActorDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamActor, AActor*, Actor);
