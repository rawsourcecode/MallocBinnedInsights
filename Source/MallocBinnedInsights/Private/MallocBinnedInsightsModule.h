#pragma once

#include "IMallocBinnedInsightsModule.h"
#include "Modules/ModuleManager.h"

#if !WITH_EDITOR
#include "MallocBinnedInsightsTimingViewExtender.h"
#endif

namespace UE::Insights::MemoryProfiler::MallocBinned
{
#if !WITH_EDITOR
	class FMallocBinnedInsightsComponent;
#endif
	
	class FMallocBinnedInsightsModule final : public IMallocBinnedInsightsModule
	{
	public:
		virtual void StartupModule() override;
		virtual void ShutdownModule() override;

	private:
#if !WITH_EDITOR
		TSharedPtr<FMallocBinnedInsightsComponent> MallocBinnedInsightsComponent;
		FMallocBinnedInsightsTimingViewExtender MallocBinnedInsightsTimingViewExtender;
#endif // !WITH_EDITOR
	};
}
