#ifndef __FRACTAL_ENGINE_EDITORSYNCTOOL_H__
#define __FRACTAL_ENGINE_EDITORSYNCTOOL_H__

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/TextEditor.h>

#include <soundTrack.h>

#include <iostream>

namespace Editor
{
	namespace SyncTool
	{
		class EditorSyncTool
		{
		public:
			float						tempo = 0;

			HighLevel::SoundTrack		soundTrack;
			void						Sync_Tool();
		};
	}
}

#endif //__FRACTAL_ENGINE_EDITORSYNCTOOL_H__
