#include <editorWindow.h>
#include <bass.h>

using namespace Editor;

#define EDITOR_SET_LIGHT_MODE		ImGui::StyleColorsLight();
#define EDITOR_SET_DARK_MODE		ImGui::StyleColorsDark();

EditorWindow::EditorWindow(){};

EditorWindow::~EditorWindow()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void EditorWindow::ImGui_Initialisation(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");
}

void EditorWindow::Editor_WindowSetUp(TextEditor& editor, Graphics::Renderer& renderer)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	EditorWindow::Editor_GUIsetUp(editor, renderer);
}

void EditorWindow::Editor_Rendering()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EditorWindow::Editor_GUIsetUp(TextEditor& editor, Graphics::Renderer& renderer)
{		
	Editor_MainToolBar(editor, renderer);
	IDE_Render(editor, renderer);
	IDE_ShortCuts(editor, renderer);
}

void EditorWindow::IDE_Render(TextEditor& editor, Graphics::Renderer& renderer)
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

void EditorWindow::Editor_MainToolBar(TextEditor& editor, Graphics::Renderer& renderer)
{
	switch (themeOfEditor)
	{
	case 0:
		EDITOR_SET_LIGHT_MODE;
		break;
	case 1:
		EDITOR_SET_DARK_MODE;
		break;
	}

	ImGui::BeginMainMenuBar();

	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("Open", "Ctrl-O"))
		{
			IDE_Open_File(editor, renderer);
		}
		if (ImGui::MenuItem("Save", "Ctrl-S"))
		{
			IDE_Save_File(editor, renderer);
		}
		if (ImGui::MenuItem("ClearConsole"))
		{
			system("cls");
		}
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Edit"))
	{
		bool ro = editor.IsReadOnly();

		if (ImGui::MenuItem("Read-only mode", nullptr, &ro))
			editor.SetReadOnly(ro);
		if (ImGui::MenuItem("Undo", "ALT-Backspace", nullptr, !ro && editor.CanUndo()))
			editor.Undo();
		if (ImGui::MenuItem("Redo", "Ctrl-Y", nullptr, !ro && editor.CanRedo()))
			editor.Redo();

		ImGui::Separator();

		if (ImGui::MenuItem("Copy", "Ctrl-C", nullptr, editor.HasSelection()))
			editor.Copy();
		if (ImGui::MenuItem("Cut", "Ctrl-X", nullptr, !ro && editor.HasSelection()))
			editor.Cut();
		if (ImGui::MenuItem("Delete", "Del", nullptr, !ro && editor.HasSelection()))
			editor.Delete();
		if (ImGui::MenuItem("Paste", "Ctrl-V", nullptr, !ro && ImGui::GetClipboardText() != nullptr))
			editor.Paste();

		ImGui::Separator();

		if (ImGui::MenuItem("Select all", nullptr, nullptr))
			editor.SetSelection(TextEditor::Coordinates(), TextEditor::Coordinates(editor.GetTotalLines(), 0));

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Settings"))
	{
		if (ImGui::BeginMenu("Editor Window Theme"))
		{
			if (ImGui::MenuItem("Light"))
			{
				themeOfEditor = 0;
			}
			if (ImGui::MenuItem("Dark"))
			{
				themeOfEditor = 1;
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("IDE Window Theme"))
		{
			if (ImGui::MenuItem("Dark palette"))
				editor.SetPalette(TextEditor::GetDarkPalette());
			if (ImGui::MenuItem("Light palette"))
				editor.SetPalette(TextEditor::GetLightPalette());
			if (ImGui::MenuItem("Retro blue palette"))
				editor.SetPalette(TextEditor::GetRetroBluePalette());
			ImGui::EndMenu();
		}
		ImGui::EndMenu();
	}
	ImGui::EndMainMenuBar();
}

void EditorWindow::IDE_ShortCuts(TextEditor& editor, Graphics::Renderer& renderer)
{
	if (ImGui::IsKeyDown(ImGuiMod_Ctrl) && ImGui::IsKeyDown(ImGuiKey_S))
	{
		IDE_Save_File(editor, renderer);
	}
	if (ImGui::IsKeyDown(ImGuiMod_Ctrl) && ImGui::IsKeyDown(ImGuiKey_O))
	{
		IDE_Open_File(editor, renderer);
	}
}

void EditorWindow::IDE_Open_File(TextEditor& editor, Graphics::Renderer& renderer)
{
	renderer.fragmentShaderPath = "";
	renderer.Renderer_ReadAndCompileShader();
	editor.SetText(renderer.m_fragmentShader);
}

void EditorWindow::IDE_Save_File(TextEditor& editor, Graphics::Renderer& renderer)
{
	std::ofstream file(renderer.fragmentShaderPath, std::ofstream::out);
	file << editor.GetText();
	file.close();
}