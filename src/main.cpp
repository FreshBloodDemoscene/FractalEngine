#include <iostream>

#include <editorWindow.h>
#include <window.h>
#include <renderer.h>
#include <file.h>
#include <soundTrack.h>

#define GLEW_STATIC
#include <GL/glew.h>

int main(int argc, char** argv)
{
	File file;
	Window window;
	EditorWindow editorWindow;
	SoundTrack soundtrack;
	Renderer renderer(window);

	//auto music_selection = pfd::open_file("Select Music", ".", {"Music Files", "*.wav *.mp3"}).result();
	//
	//for (auto const &filename : music_selection)
	//{
	//	soundtrack.PlayMusic(filename);
	//}

	editorWindow.ImGuiInitialisation(window.m_window);

	do
	{
		editorWindow.EditorWindowSetUp(renderer);

		renderer.Render();
		file.UpdateFile(renderer, window, 1);
		editorWindow.EditorRendering();

	} while (window.SwapBuffers());

	return 0;
}