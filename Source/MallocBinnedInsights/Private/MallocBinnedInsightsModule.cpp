// Copyright Epic Games, Inc. All Rights Reserved.

#include "MallocBinnedInsightsModule.h"
#include "Insights/ITimingViewExtender.h"

#define LOCTEXT_NAMESPACE "FMallocBinnedInsightsModule"

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	void FMallocBinnedInsightsModule::StartupModule()
	{
		UE_LOG(LogTemp, Log, TEXT("Hello binned"));
#if !WITH_EDITOR
		IModularFeatures::Get().RegisterModularFeature(UE::Insights::Timing::TimingViewExtenderFeatureName, &MallocBinnedInsightsTimingViewExtender);
#endif
	}

	void FMallocBinnedInsightsModule::ShutdownModule()
	{
		// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
		// we call this function before unloading the module.
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(UE::Insights::MemoryProfiler::MallocBinned::FMallocBinnedInsightsModule, MallocBinnedInsights)
