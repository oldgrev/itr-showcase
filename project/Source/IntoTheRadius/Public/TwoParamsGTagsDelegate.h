#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TwoParamsGTagsDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwoParamsGTagsDelegate, FGameplayTag, tagOne, FGameplayTag, tagTwo);
