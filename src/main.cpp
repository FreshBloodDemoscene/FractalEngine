#include <iostream>

#include <editorWindow.h>
#include <window.h>
#include <renderer.h>
#include <file.h>
#include <soundTrack.h>
#include <synctracker.h>
#include <rocketValues.h>

#define GLEW_STATIC
#include <GL/glew.h>

int main(int argc, char** argv)
{
	File file;
	Window window;
	EditorWindow editorWindow;
	SoundTrack soundtrack;
	Renderer renderer(window);
	//SyncTracker syncTracker;
	SoundTrack s;
	//RocketValues rV;

	//auto selection = pfd::open_file("Choose Music", ".", { "*.wav *.mp3" }).result();
	//for (auto const& filename : selection)
	//{
	//	s.PlayMusic(filename);
	//}
	

	editorWindow.ImGuiInitialisation(window.m_window);


	do
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//rV.setUpRocketValues(syncTracker, renderer);

		//syncTracker.Update(s);
		renderer.Render();
		file.UpdateFile(renderer, window, /*float(s.CurrentTime())*/1);

		editorWindow.EditorWindowSetUp(renderer);
		
		editorWindow.EditorRendering();
	} while (window.SwapBuffers() /*&& (SoundTrack::ms_IsPlaying(&s))*/);

	return 0;
}