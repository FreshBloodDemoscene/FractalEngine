#ifndef __FRACTAL_ENGINE_EDITORWINDOW_H__
#define __FRACTAL_ENGINE_EDITORWINDOW_H__

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/TextEditor.h>

#include <iostream>
#include <renderer.h>
#include <window.h>

#include <string>
#include <fstream>
#include <ostream>

#define GLEW_STATIC
#include <GL/glew.h>

namespace Editor
{
	class EditorWindow
	{
	public:
		explicit EditorWindow();
		~EditorWindow();

		void ImGuiInitialisation	(GLFWwindow* window);
		void EditorWindowSetUp		(TextEditor& editor, Graphics::Renderer& renderer);
		void EditorRendering		();
		void EditorGUIsetUp			(TextEditor& editor, Graphics::Renderer& renderer);
		void IDE_Render				(TextEditor& editor, Graphics::Renderer& renderer);

		void MainToolBar			(TextEditor& editor, Graphics::Renderer& renderer);

		void IDE_ShortCuts			(TextEditor& editor, Graphics::Renderer& renderer);
		void Open_File				(Graphics::Renderer& renderer);
		void Save_File				(TextEditor& editor, Graphics::Renderer& renderer);
		int							ThemeOfEditor = 1;
	};
}
#endif	//__FRACTAL_ENGINE_EDITORWINDOW_H__
