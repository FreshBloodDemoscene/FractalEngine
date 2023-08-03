#include <file.h>
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#define VERTEXSHADER_LAST_TIME_EDITED	 std::filesystem::last_write_time(vertex_shader_path);
#define FRAGMENTSHADER_LAST_TIME_EDITED  std::filesystem::last_write_time(fragment_shader_path);



File::File()
{	
}

File::~File() noexcept
{
}

void File::CheckModification()
{	
	auto check_fs_modification = std::filesystem::last_write_time(fragment_shader_path);
	auto check_vs_modification = std::filesystem::last_write_time(vertex_shader_path);

	if(fs_changed != check_fs_modification || vs_changed != check_vs_modification)
	{
		status = E_FileStatus::modified;

		fs_changed = check_fs_modification;
		vs_changed = check_vs_modification;
	}
	else
	{
		status = E_FileStatus::nothingChanged;
	}
}

void File::UpdateFile(Renderer& render, Window& window, float t)
{
	if (!render.fragmentShaderPath.empty() || !render.vertexShaderPath.empty())
	{
		if (doOnce == 0)
		{
			fragment_shader_path = render.fragmentShaderPath;
			vertex_shader_path = render.vertexShaderPath;

			fs_changed = FRAGMENTSHADER_LAST_TIME_EDITED;
			vs_changed = VERTEXSHADER_LAST_TIME_EDITED;

			doOnce = 1;
		}

		//IF VERTEX OR FRAGMENT CHANGED, THEN UPDATE VARIABLES PATH TO UPDATE HOT RELOAD
		if (fragment_shader_path != render.fragmentShaderPath)
		{
			fragment_shader_path = render.fragmentShaderPath;
			fs_changed = FRAGMENTSHADER_LAST_TIME_EDITED;
		}
		if (vertex_shader_path != render.vertexShaderPath)
		{
			vertex_shader_path = render.vertexShaderPath;
			vs_changed = VERTEXSHADER_LAST_TIME_EDITED;
		}

	}

	CheckModification();
	switch (status)
	{
	case E_FileStatus::modified:
	{	
		render.ReadAndWrite_Shader();
		glProgramUniform2f(render.m_shader, 0, float(window.Size().x), float(window.Size().y));
	}
	break;
	case E_FileStatus::nothingChanged:
		break;
	default:
		break;
	}
	glProgramUniform1f(render.m_shader, 1, t);
}





