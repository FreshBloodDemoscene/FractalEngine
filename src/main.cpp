#include <iostream>

#include <editorWindow.h>
#include <window.h>
#include <renderer.h>
#include <file.h>

#include <ShObjIdl.h>

#define GLEW_STATIC
#include <GL/glew.h>

int main(int argc, char** argv)
{
	File file;
	Window window;
	EditorWindow editorWindow;

	Renderer renderer(window);

	editorWindow.ImGuiInitialisation(window.m_window);

	do
	{
		editorWindow.EditorWindowSetUp();

		renderer.Render();
		file.UpdateFile(renderer, window, 1);
		editorWindow.EditorRendering();

	} while (window.SwapBuffers());
	
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();


	return 0;
}