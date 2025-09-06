// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MallocBinnedInsights : ModuleRules
{
	public MallocBinnedInsights(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
				"TraceInsights",
				"TraceServices"
			});

		if (Target.Type == TargetType.Editor)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
					"UnrealEd",
				});
		}
	}
}
