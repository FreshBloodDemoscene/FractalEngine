#include <editorWindow.h>

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
	ImGui::StyleColorsLight();
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

	if(ImGui::Begin("Fractal Editor"))
	{
		ImGui::BeginMainMenuBar();
		if (ImGui::BeginMenu("File"))
		{
			if(ImGui::MenuItem("Open"))
			{
				renderer.ReadAndWrite_Shader();
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
	ImGui::End();
}