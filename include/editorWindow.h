#ifndef __FRACTAL_ENGINE_EDITORWINDOW_H__
#define __FRACTAL_ENGINE_EDITORWINDOW_H__

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <iostream>
#include <renderer.h>
#include <window.h>

#define GLEW_STATIC
#include <GL/glew.h>

class EditorWindow
{
public:
	explicit EditorWindow();
	~EditorWindow();

	void ImGuiInitialisation(GLFWwindow* window);
	void EditorWindowSetUp(Renderer& renderer);
	void EditorRendering();
	void EditorGUIsetUp(Renderer& renderer);

};
#endif	//__FRACTAL_ENGINE_EDITORWINDOW_H__
