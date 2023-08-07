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
	TextEditor				editor;

	HighLevel::SoundTrack	s;

	editorWindow.ImGui_Initialisation(window.m_window);

	do
	{
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.Render();

		editorWindow.Editor_WindowSetUp(editor, renderer);
		editorWindow.Editor_Rendering();

		file.File_Update(renderer, window, 1);

	} while (window.Window_SwapBuffers());

	return 0;
}