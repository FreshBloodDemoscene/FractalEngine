#ifndef __FRACTAL_ENGINE_SHADER_H__
#define __FRACTAL_ENGINE_SHADER_H__

#include <iostream>
#include <vector>


#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Graphics
{
	class Shader
	{
		unsigned int m_shader;
	public:
		explicit Shader(unsigned int Shader);
		~Shader() noexcept;

		operator unsigned int();
	};
}


#endif //__FRACTAL_ENGINE_SHADER_H__
