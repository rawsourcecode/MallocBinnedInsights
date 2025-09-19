#include "MallocBinnedInsightsModule.h"

#include "Features/IModularFeatures.h"
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
#if !WITH_EDITOR
		IModularFeatures::Get().UnregisterModularFeature(UE::Insights::Timing::TimingViewExtenderFeatureName, &MallocBinnedInsightsTimingViewExtender);

		IUnrealInsightsModule& UnrealInsightsModule = FModuleManager::LoadModuleChecked<IUnrealInsightsModule>("TraceInsights");
		UnrealInsightsModule.UnregisterComponent(MallocBinnedInsightsComponent);
#endif // !WITH_EDITOR
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(UE::Insights::MemoryProfiler::MallocBinned::FMallocBinnedInsightsModule, MallocBinnedInsights)
