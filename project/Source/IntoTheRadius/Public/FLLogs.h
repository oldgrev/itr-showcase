#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLLogs.generated.h"

class UObject;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLLogs : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLLogs(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void SwitchWorldDumpLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchSpawnerLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchSpawnerDebug();

    UFUNCTION(BlueprintCallable)
    static void SwitchSingletonsLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchSavesLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchPoolLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchLootTablesLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchLogsEnabled();

    UFUNCTION(BlueprintCallable)
    static void SwitchLevelsLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchInventoryLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchINILogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchGameReferencesLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchGameModeLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchGameDataLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchDetailedEventsLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchDataParsingLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchConditionsLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchClusterLogs();

    UFUNCTION(BlueprintCallable)
    static void SwitchBasicActorLogs();

    UFUNCTION(BlueprintCallable)
    static void PRLogStacktrace(bool Warning, const FString& Message);

    UFUNCTION(BlueprintCallable)
    static void PRLogNormal(const FString& Message);

    UFUNCTION(BlueprintCallable)
    static void PRLogLines(const FString& Message);

    UFUNCTION(BlueprintCallable)
    static void PRLogError(const FString& Message);

    UFUNCTION(BlueprintCallable)
    static void PRLogBanner(const FString Symbol, const FString Message);

    UFUNCTION(BlueprintPure)
    static bool PrintWorldDumpLogs();

    UFUNCTION(BlueprintCallable)
    static void PrintWorldDump(const UObject* WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool PrintSpawnerLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintSingletonsLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintSavesLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintPoolLogs();

    UFUNCTION(BlueprintCallable)
    static void PrintNPCDump(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void PrintMissionsDataDump();

    UFUNCTION(BlueprintPure)
    static bool PrintLootTablesLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintLevelsLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintInventoryLogs();

    UFUNCTION(BlueprintCallable)
    static void PrintInventoryDataDump();

    UFUNCTION(BlueprintPure)
    static bool PrintINILogs();

    UFUNCTION(BlueprintPure)
    static bool PrintGameReferencesLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintGameModeLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintGameDataLogs();

    UFUNCTION(BlueprintCallable)
    static void PrintGameDataDump();

    UFUNCTION(BlueprintPure)
    static bool PrintDetailedEventsLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintDataParsingLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintConditionsLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintClusterLogs();

    UFUNCTION(BlueprintPure)
    static bool PrintBasicActorLogs();

    UFUNCTION(BlueprintCallable)
    static void LogToFile(const FString Message);

    UFUNCTION(BlueprintPure)
    static bool LogsEnabled();

    UFUNCTION(BlueprintPure)
    static bool IsEnabledTeleportDebug();

    UFUNCTION(BlueprintPure)
    static bool IsEnabledPlayerStatsLogs();

    UFUNCTION(BlueprintPure)
    static bool IsEnabledBTRDebug();

    UFUNCTION(BlueprintPure)
    static bool IsEnabledAnomaliesLogs();

    UFUNCTION(BlueprintPure)
    static bool IsAIStateDebugEnabled();

    UFUNCTION(BlueprintPure)
    static bool IsAICoverDebugEnabled();

    UFUNCTION(BlueprintPure)
    static float GetTeleportDebugTime();

    UFUNCTION(BlueprintPure)
    static bool DrawSpawnerDebug();

};
