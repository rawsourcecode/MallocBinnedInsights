// Copyright Epic Games, Inc. All Rights Reserved.

#include "MallocBinnedInsight.h"

#define LOCTEXT_NAMESPACE "FMallocBinnedInsightModule"

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	void FMallocBinnedInsightModule::StartupModule()
	{
		// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	}

	void FMallocBinnedInsightModule::ShutdownModule()
	{
		// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
		// we call this function before unloading the module.
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMallocBinnedInsightModule, MallocBinnedInsight)