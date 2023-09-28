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
#include <soundTrack.h>
#include <window.h>

#define GLEW_STATIC
#include <GL/glew.h>

namespace Editor
{
	class EditorWindow
	{
	private:
		int							themeOfEditor			= 1;
		float						tempo					= 0;
		float						volume					= 0;
	public:
		explicit EditorWindow();
		~EditorWindow() noexcept;
		void						ImGui_Initialisation	(GLFWwindow* window);

		void						Editor_WindowSetUp		(TextEditor& editor, Graphics::Renderer& renderer);
		void						Editor_Rendering		();
		void						Editor_GUIsetUp			(TextEditor& editor, Graphics::Renderer& renderer);
		void						Editor_MainToolBar		(TextEditor& editor, Graphics::Renderer& renderer);

		void						IDE_Render				(TextEditor& editor, Graphics::Renderer& renderer);
		void						IDE_ShortCuts			(TextEditor& editor, Graphics::Renderer& renderer);
		void						IDE_Open_File			(TextEditor& editor, Graphics::Renderer& renderer);
		void						IDE_Save_File			(TextEditor& editor, Graphics::Renderer& renderer);
		
		void						Sync_Tool			();

		HighLevel::SoundTrack		soundTrack;
	};
}
#endif	//__FRACTAL_ENGINE_EDITORWINDOW_H__
