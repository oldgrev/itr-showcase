using UnrealBuildTool;

public class IntoTheRadiusEditorTarget : TargetRules {
	public IntoTheRadiusEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		// G1 scratch: ITR_MobileShaders and OnlineSubsystemOculus dropped (not needed to load gameplay BPs)
		ExtraModuleNames.AddRange(new string[] {
			"IntoTheRadius",
		});
	}
}
