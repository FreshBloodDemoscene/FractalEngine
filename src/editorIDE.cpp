#include <editorIDE.h>

using namespace Editor::IDE;

void EditorIDE::Render(TextEditor& editor, Graphics::Renderer& renderer)
{
	static bool s_firstTimeSetUp = false;
	if (!s_firstTimeSetUp)
	{
		auto lang = TextEditor::LanguageDefinition::GLSL();
		editor.SetLanguageDefinition(lang);

		if (!renderer.m_fragmentShader.empty())
		{
			editor.SetText(renderer.m_fragmentShader);
		}

		s_firstTimeSetUp = true;
	}
	if (ImGui::Begin("Fractal Engine - IDE", nullptr, ImGuiWindowFlags_NoNav))
	{
		editor.Render("ShaderEditor");
	}
	ImGui::End();
}

void EditorIDE::ShortCuts(TextEditor& editor, Graphics::Renderer& renderer)
{
	if (ImGui::IsKeyDown(ImGuiMod_Ctrl) && ImGui::IsKeyDown(ImGuiKey_S))
	{
		Save_File(editor, renderer);
	}
	if (ImGui::IsKeyDown(ImGuiMod_Ctrl) && ImGui::IsKeyDown(ImGuiKey_O))
	{
		Open_File(editor, renderer);
	}
	if (ImGui::IsKeyDown(ImGuiMod_Ctrl) && ImGui::IsKeyDown(ImGuiKey_D))
	{
		DockingWindow();
	}
}

void EditorIDE::Open_File(TextEditor& editor, Graphics::Renderer& renderer)
{
	renderer.fragmentShaderPath = "";
	renderer.ReadAndCompileShader();
	editor.SetText(renderer.m_fragmentShader);
}

void EditorIDE::Save_File(TextEditor& editor, Graphics::Renderer& renderer)
{
	std::ofstream file(renderer.fragmentShaderPath, std::ofstream::out);
	file << editor.GetText();
	file.close();
}

void EditorIDE::DockingWindow()
{
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}
