#include <iostream>

#include <editorWindow.h>
#include <window.h>
#include <renderer.h>
#include <file.h>
#include <soundTrack.h>
#include <synctracker.h>
#include <rocketValues.h>
#include <TextEditor.h>

#define	GLEW_STATIC
#include <GL/glew.h>

using namespace Core;
using namespace Graphics;
using namespace HighLevel;
using namespace Editor;

int main(int argc, char** argv)
{
	File					file;
	Window					window;
	EditorWindow			editorWindow;
	Renderer				renderer(window);
	TextEditor				editor;

	HighLevel::SoundTrack	s;

	editorWindow.ImGuiInitialisation(window.m_window);

	do
	{
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.Render();

		editorWindow.EditorWindowSetUp(editor, renderer);
		editorWindow.EditorRendering();

		file.UpdateFile(renderer, window, /*float(s.CurrentTime())*/1);

	} while (window.SwapBuffers() /*&& (SoundTrack::ms_IsPlaying(&s))*/);

	return 0;
}