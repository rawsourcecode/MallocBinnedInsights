// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IMallocBinnedInsightsModule.h"
#include "Modules/ModuleManager.h"

#if !WITH_EDITOR
#include "MallocBinnedInsightsTimingViewExtender.h"
#endif

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	class FMallocBinnedInsightsModule final : public IMallocBinnedInsightsModule
	{
	public:
		virtual void StartupModule() override;
		virtual void ShutdownModule() override;

	private:
#if !WITH_EDITOR
		FMallocBinnedInsightsTimingViewExtender MallocBinnedInsightsTimingViewExtender;
#endif // !WITH_EDITOR
	};
}
