// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Assigment2 : ModuleRules
{
	public Assigment2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "EnhancedInput",
            "InputCore",
            "UMG"
        });

        PublicIncludePaths.AddRange(new string[] { "EnhanceInput/Public" });/**/
        //PublicIncludePaths.AddRange(new string[] { "C:\\Program Files\\Epic Games\\UE_5.2\\Engine\\Plugins\\EnhancedInput\\Source\\EnhancedInput\\Public" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
