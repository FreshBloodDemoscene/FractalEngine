#include <editorSyncTool.h>

using namespace Editor::SyncTool;

void EditorSyncTool::Sync_Tool()
{
	if (ImGui::Begin("Fractal Engine - SyncTool", nullptr, ImGuiWindowFlags_NoNav))
	{
		if (ImGui::SliderFloat("Volume", &soundTrack.volume, 0.0f, 1.0f, "%.3f", 0))
		{
			soundTrack.SetVolume();
		}

		if (ImGui::Button("Pause", ImVec2(150, 20)))
		{
			soundTrack.SoundTrack_Pause();
		}

		if (ImGui::Button("Play", ImVec2(150, 20)))
		{
			soundTrack.SoundTrack_Unpause();
		}

		if (ImGui::Button("Mute", ImVec2(150, 20)))
		{
			soundTrack.Mute(true);
		}

		ImGui::SameLine();
		if (ImGui::Button("UnMute", ImVec2(150, 20)))
		{
			soundTrack.Mute(false);
		}

		ImGui::Separator();

		for (int i = 0; i < soundTrack.timeNeeded; i++)
		{
			ImGui::Text("%d", i);
			ImGui::Separator(); 
		}

	}
	ImGui::End();
}
