// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CryptRider_01 : ModuleRules
{
	public CryptRider_01(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
