#include "NpcPointQueryManager.h"

UNpcPointQueryManager::UNpcPointQueryManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

UNpcPointQueryManager* UNpcPointQueryManager::GetNpcPointQueryManager() {
    return {};
}

FNpcPointQueryHandle UNpcPointQueryManager::FindShootingPoint(const FNpcPointQueryParam& Param, FPointQueryCompleteDelegate FinishCallback, ENpcPointQueryType QueryType) {
    return {};
}

FNpcPointQueryHandle UNpcPointQueryManager::FindCoverPoint(const FNpcPointQueryParam& Param, FPointQueryCompleteDelegate FinishCallback) {
    return {};
}

void UNpcPointQueryManager::CancelQuery(UPARAM(ref) FNpcPointQueryHandle& Handle) {
}

