#ifndef __FRACTAL_ENGINE_TEXTLOADER_H__
#define __FRACTAL_ENGINE_TEXTLOADER_H__

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Graphics
{
	class textLoader
	{
		unsigned int	texture;
	public:
		void			TextLoader_LoadImage		(const char* image_path, int width, int height
													, int nrChannels, int req_comp);
		void			TextLoader_Use				(unsigned int unit);
	};
}
#endif	//__FRACTAL_ENGINE_TEXTLOADER_H__

