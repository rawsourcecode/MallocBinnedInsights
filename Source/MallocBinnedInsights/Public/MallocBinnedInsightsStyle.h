#pragma once

#include "Styling/SlateStyleMacros.h"
#include "Styling/StyleColors.h"
#include "Styling/SlateStyleRegistry.h"

namespace UE::Insights::MemoryProfiler::MallocBinned
{
	class FSlateStyle final : public FSlateStyleSet
	{
	public:
		static FSlateStyle& Get()
		{
			static FSlateStyle InsightsStyle;
			return InsightsStyle;
		}

		FName GetStyleName() // Not static to force call of FSlateStyle::Get which constructs this style object
		{
			const FLazyName StyleName = "MallocBinnedInsights";
			return StyleName.Resolve();
		}

		FSlateIcon CreateIcon(FName InName)
		{
			return { GetStyleName(), InName };
		}

		FSlateStyle()
			: FSlateStyleSet(GetStyleName())
		{
			SetParentStyleName(FAppStyle::GetAppStyleSetName());

			const FString PluginsDir = FPaths::EnginePluginsDir();

			SetContentRoot(PluginsDir / TEXT("MallocBinnedInsights/Content"));
			SetCoreContentRoot(PluginsDir / TEXT("Slate"));

			// Icons
			const FVector2D Icon16(16.0f, 16.0f);
			const FVector2D Icon20(20.0f, 20.0f);
			const FVector2D Icon24(24.0f, 24.0f);
			const FVector2D Icon64(64.0f, 64.0f);

			Set("MallocBinnedInsights.Icon", new IMAGE_BRUSH_SVG(TEXT("Icons/malloc_binned_insights_icon"), Icon16));
						
			FSlateStyleRegistry::RegisterSlateStyle(*this);
		}
	};
}
