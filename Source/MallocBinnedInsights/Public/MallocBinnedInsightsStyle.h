#pragma once

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

		static FName GetStyleName()
		{
			const FLazyName StyleName = "MallocBinnedInsights";
			return StyleName.Resolve();
		}

		FSlateStyle()
			: FSlateStyleSet(GetStyleName())
		{
			FSlateStyleRegistry::RegisterSlateStyle(*this);
		}
	};
}
