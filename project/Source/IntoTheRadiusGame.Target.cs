using UnrealBuildTool;

public class IntoTheRadiusGameTarget : TargetRules {
	public IntoTheRadiusGameTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] {
			"IntoTheRadius",
		});
	}
}
