#include <file.h>

using namespace Core;

#define FRAGMENTSHADER_LAST_TIME_EDITED  std::filesystem::last_write_time(fragment_shader_path);

File::File(){}

File::~File() noexcept{}

void File::CheckModification()
{	
	auto check_fs_modification = std::filesystem::last_write_time(fragment_shader_path);

	if(fs_changed != check_fs_modification)
	{
		status = E_FileStatus::modified;
		fs_changed = check_fs_modification;
	}
	else
	{
		status = E_FileStatus::nothingChanged;
	}
}

void File::Update(Graphics::Renderer& render, Window& window, float t)
{
	if (!render.fragmentShaderPath.empty())
	{
		static int doOnce = 0;
		if (doOnce == 0)
		{
			fragment_shader_path = render.fragmentShaderPath;
			fs_changed = FRAGMENTSHADER_LAST_TIME_EDITED;
			doOnce = 1;
		}
		if (fragment_shader_path != render.fragmentShaderPath)
		{
			fragment_shader_path = render.fragmentShaderPath;
			fs_changed = FRAGMENTSHADER_LAST_TIME_EDITED;
		}
	}

	CheckModification();
	switch (status)
	{
	case E_FileStatus::modified:
	{	
		render.ReadAndCompileShader();
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





