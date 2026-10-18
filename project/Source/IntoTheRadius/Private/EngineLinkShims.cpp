#include "Sound/AudioVolume.h"
#include "AudioDefines.h"

// copied from Engine/Source/Runtime/Engine/Private/AudioVolume.cpp (not exported from the engine DLL)
FInteriorSettings::FInteriorSettings()
	: bIsWorldSettings(false)
	, ExteriorVolume(1.0f)
	, ExteriorTime(0.5f)
	, ExteriorLPF(MAX_FILTER_FREQUENCY)
	, ExteriorLPFTime(0.5f)
	, InteriorVolume(1.0f)
	, InteriorTime(0.5f)
	, InteriorLPF(MAX_FILTER_FREQUENCY)
	, InteriorLPFTime(0.5f)
{
}

