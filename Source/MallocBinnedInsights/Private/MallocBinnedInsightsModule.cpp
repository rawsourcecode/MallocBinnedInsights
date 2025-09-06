#include "MallocBinnedInsightsModule.h"

#include "Features/IModularFeatures.h"
#include "Framework/Docking/TabManager.h"
#include "MallocBinnedInsightsComponent.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FMallocBinnedInsightsModule"

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	void FMallocBinnedInsightsModule::StartupModule()
	{
#if !WITH_EDITOR
		IModularFeatures::Get().RegisterModularFeature(UE::Insights::Timing::TimingViewExtenderFeatureName, &MallocBinnedInsightsTimingViewExtender);

		MallocBinnedInsightsComponent = FMallocBinnedInsightsComponent::CreateInstance();

		IUnrealInsightsModule& UnrealInsightsModule = FModuleManager::LoadModuleChecked<IUnrealInsightsModule>("TraceInsights");
		UnrealInsightsModule.RegisterComponent(MallocBinnedInsightsComponent);
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
