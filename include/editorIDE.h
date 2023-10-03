#ifndef __FRACTAL_ENGINE_EDITORIDE_H__
#define __FRACTAL_ENGINE_EDITORIDE_H__

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/TextEditor.h>

#include <renderer.h>

namespace Editor
{
	namespace IDE
	{
		class EditorIDE 
		{
		public:
			void						Render(TextEditor& editor, Graphics::Renderer& renderer);
			void						ShortCuts(TextEditor& editor, Graphics::Renderer& renderer);
			void						Open_File(TextEditor& editor, Graphics::Renderer& renderer);
			void						Save_File(TextEditor& editor, Graphics::Renderer& renderer);
			void						DockingWindow();
		};

	}
}

#endif //__FRACTAL_ENGINE_EDITORIDE_H__