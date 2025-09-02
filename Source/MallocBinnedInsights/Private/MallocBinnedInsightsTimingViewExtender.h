#pragma once

#include "Insights/ITimingViewExtender.h"

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	class FMallocBinnedInsightsTimingViewExtender : public UE::Insights::Timing::ITimingViewExtender
	{
	public:
		virtual void OnBeginSession(UE::Insights::Timing::ITimingViewSession& InSession) override;
		virtual void OnEndSession(UE::Insights::Timing::ITimingViewSession& InSession) override;
		virtual void Tick(UE::Insights::Timing::ITimingViewSession& InSession, const TraceServices::IAnalysisSession& InAnalysisSession) override;
	};
}
