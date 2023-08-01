#ifndef __FRACTAL_ENGINE_EDITORWINDOW_H__
#define __FRACTAL_ENGINE_EDITORWINDOW_H__

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

class EditorWindow
{
public:
	explicit EditorWindow();
	~EditorWindow();

	void ImGuiInitialisation(GLFWwindow* window);
	void EditorWindowSetUp();
	void EditorRendering();
	void EditorGUIsetUp();
};
#endif	//__FRACTAL_ENGINE_EDITORWINDOW_H__