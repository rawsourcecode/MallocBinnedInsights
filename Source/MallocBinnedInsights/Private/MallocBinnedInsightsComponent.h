#pragma once

#include "Insights/IUnrealInsightsModule.h"
#include "Templates/SharedPointer.h"

class SDockTab;
class FSpawnTabArgs;

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	class FMallocBinnedInsightsComponent : public IInsightsComponent, public TSharedFromThis<FMallocBinnedInsightsComponent>
	{
	public:
		virtual ~FMallocBinnedInsightsComponent() = default;
		
		static TSharedPtr<FMallocBinnedInsightsComponent> CreateInstance();

		// Interface IInsightsComponent

		virtual void Initialize(IUnrealInsightsModule& Module) override;
		virtual void Shutdown() override;
		virtual void RegisterMajorTabs(IUnrealInsightsModule& InsightsModule) override;
		virtual void UnregisterMajorTabs() override;

	private:
		bool CanSpawnTab(const FSpawnTabArgs& Args) const;
		TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& Args);

	private:
		static inline TSharedPtr<FMallocBinnedInsightsComponent> Instance;
	};
}


