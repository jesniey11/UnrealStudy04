// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class study04 : ModuleRules
{
	public study04(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
