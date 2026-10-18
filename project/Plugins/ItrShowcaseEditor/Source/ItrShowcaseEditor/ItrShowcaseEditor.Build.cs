using UnrealBuildTool;

public class ItrShowcaseEditor : ModuleRules {
	public ItrShowcaseEditor(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
		PrivateDependencyModuleNames.AddRange(new string[] {
			"UnrealEd", "BlueprintGraph", "KismetCompiler", "Kismet", "Json", "AssetRegistry", "Slate", "SlateCore",
			"ImageWrapper", "TargetPlatform", "RHI", "RenderCore", "PhysicsCore"   // ItrShowcaseAudit (T-116)
		});
	}
}
