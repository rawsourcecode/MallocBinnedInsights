#pragma once

#include "TraceServices/ModuleService.h"

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	class FMallocBinnedInsightsTraceModule : public TraceServices::IModule
	{
	public:
		FMallocBinnedInsightsTraceModule() = default;
		virtual ~FMallocBinnedInsightsTraceModule() = default;

		virtual void GetModuleInfo(TraceServices::FModuleInfo& OutModuleInfo) override;
		virtual void OnAnalysisBegin(TraceServices::IAnalysisSession& Session) override;
	};
}
