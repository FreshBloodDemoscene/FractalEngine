#ifndef __FRACTAL_ENGINE_EDITORWINDOW_H__
#define __FRACTAL_ENGINE_EDITORWINDOW_H__

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/TextEditor.h>

#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

#include <renderer.h>

#include <window.h>

#include <editorIDE.h>
#include <editorSyncTool.h>

#define GLEW_STATIC
#include <GL/glew.h>

namespace Editor
{
	class EditorWindow
	{
	private:
		int									themeOfEditor			= 1;
	public:		
		explicit EditorWindow();
		~EditorWindow() noexcept;
		void								ImGui_Initialisation	(GLFWwindow* window);

		void								Editor_WindowSetUp		(TextEditor& editor, Graphics::Renderer& renderer);
		void								Editor_Rendering		();
		void								Editor_GUIsetUp			(TextEditor& editor, Graphics::Renderer& renderer);
		void								Editor_MainToolBar		(TextEditor& editor, Graphics::Renderer& renderer);

		Editor::IDE::EditorIDE				editorIDE;
		Editor::SyncTool::EditorSyncTool	editorSyncTool;
	};
}
#endif	//__FRACTAL_ENGINE_EDITORWINDOW_H__
