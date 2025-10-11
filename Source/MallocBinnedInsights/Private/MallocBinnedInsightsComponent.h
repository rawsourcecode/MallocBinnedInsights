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

		// End of Interface IInsightsComponent

	private:
		bool Tick(float DeltaTime);

		bool CanSpawnTab(const FSpawnTabArgs& Args) const;
		TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& Args);

	private:
		/** True if the object was already initialized */
		bool bIsInitialized = false;
		
		/** The delegate to be invoked when this manager ticks. */
		FTickerDelegate OnTick;

		/** Handle to the registered OnTick. */
		FTSTicker::FDelegateHandle OnTickHandle;

		/** Instance to this component */
		static inline TSharedPtr<FMallocBinnedInsightsComponent> Instance;
	};
}


