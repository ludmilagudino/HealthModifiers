// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ejercicio31_03 : ModuleRules
{
	public Ejercicio31_03(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Ejercicio31_03",
			"Ejercicio31_03/Variant_Platforming",
			"Ejercicio31_03/Variant_Platforming/Animation",
			"Ejercicio31_03/Variant_Combat",
			"Ejercicio31_03/Variant_Combat/AI",
			"Ejercicio31_03/Variant_Combat/Animation",
			"Ejercicio31_03/Variant_Combat/Gameplay",
			"Ejercicio31_03/Variant_Combat/Interfaces",
			"Ejercicio31_03/Variant_Combat/UI",
			"Ejercicio31_03/Variant_SideScrolling",
			"Ejercicio31_03/Variant_SideScrolling/AI",
			"Ejercicio31_03/Variant_SideScrolling/Gameplay",
			"Ejercicio31_03/Variant_SideScrolling/Interfaces",
			"Ejercicio31_03/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
