#include "CloseCombatManagerEnemyGroup.h"

#include "ITRDefaults.h"
FCloseCombatManagerEnemyGroup::FCloseCombatManagerEnemyGroup() {
    MinEnemyAllowed = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("MinEnemyAllowed"), (double)1);
    ITRDefaults::SetNum(StaticStruct(), this, TEXT("EnemyGroup.GameplayTags"), 0);
    ITRDefaults::SetNum(StaticStruct(), this, TEXT("EnemyGroup.ParentTags"), 0);
}

FCloseCombatManagerEnemyGroup::~FCloseCombatManagerEnemyGroup() {
}
