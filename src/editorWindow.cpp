#include <editorWindow.h>

EditorWindow::EditorWindow() 
{

};

EditorWindow::~EditorWindow()
{
	//ImGui_ImplOpenGL3_Shutdown();
	//ImGui_ImplGlfw_Shutdown();
	//ImGui::DestroyContext();
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

void EditorWindow::EditorWindowSetUp()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	EditorWindow::EditorGUIsetUp();
}

void EditorWindow::EditorRendering()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EditorWindow::EditorGUIsetUp()
{
	ImGui::Begin("Fractal Editor");
	ImGui::End();
}