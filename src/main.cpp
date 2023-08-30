#include <iostream>

#include <editorWindow.h>
#include <file.h>
#include <renderer.h>
#include <rocketValues.h>
#include <soundTrack.h>
#include <synctracker.h>
#include <TextEditor.h>
#include <window.h>

#define	GLEW_STATIC
#include <GL/glew.h>

using namespace Core;
using namespace Graphics;
using namespace HighLevel;
using namespace Editor;

int main(int argc, char** argv)
{
	EditorWindow			editorWindow;
	File					file;
	Window					window;
	Renderer				renderer(window);
	//RocketValues			rV;
	TextEditor				editor;

	HighLevel::SoundTrack	s;
	//SyncTracker			syncTracker;

	glm::vec3	color = glm::vec3(1.0f, 0.0f, 0.0f);

	editorWindow.ImGui_Initialisation(window.m_window);
	
	//s.SoundTrack_PlayMusic("Evoke2023.mp3");

	do
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//rV.RocketValues_SetUp(syncTracker, renderer);

		//syncTracker.SyncTracker_Update(s);
		renderer.Render();

		editorWindow.Editor_WindowSetUp(editor, renderer);
		editorWindow.Editor_Rendering();

		file.File_Update(renderer, window, /*float(s.SoundTrack_CurrentTime()) */ 1);

	} while (window.Window_SwapBuffers() /*&& (HighLevel::SoundTrack::SoundTrack_M_IsPlaying(&s))*/);

	return 0;
}