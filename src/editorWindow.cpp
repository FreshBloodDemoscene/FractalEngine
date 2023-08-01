#include <editorWindow.h>

#define SET_LIGHT_MODE		ImGui::StyleColorsLight();
#define SET_DARK_MODE		ImGui::StyleColorsDark();

EditorWindow::EditorWindow() 
{

};

EditorWindow::~EditorWindow()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void EditorWindow::ImGuiInitialisation(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");
}

void EditorWindow::EditorWindowSetUp(Renderer& renderer)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	EditorWindow::EditorGUIsetUp(renderer);
}

void EditorWindow::EditorRendering()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EditorWindow::EditorGUIsetUp(Renderer& renderer)
{		
	MainToolBar(renderer);
}

void EditorWindow::MainToolBar(Renderer& renderer)
{
	switch (ThemeOfEditor)
	{
	case 0:
		SET_LIGHT_MODE;
		break;
	case 1:
		SET_DARK_MODE;
		break;
	}

	ImGui::BeginMainMenuBar();

	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("Open"))
		{
			renderer.ReadAndWrite_Shader();
		}
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Settings"))
	{
		if (ImGui::BeginMenu("Theme"))
		{
			if (ImGui::MenuItem("Light"))
			{
				ThemeOfEditor = 0;
			}
			if (ImGui::MenuItem("Dark"))
			{
				ThemeOfEditor = 1;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMenu();
	}
	ImGui::EndMainMenuBar();
}