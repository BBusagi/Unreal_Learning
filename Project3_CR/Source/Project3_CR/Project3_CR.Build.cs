// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Project3_CR : ModuleRules
{
	public Project3_CR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
