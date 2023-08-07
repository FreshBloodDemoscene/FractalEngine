#ifndef __FRACTALENGINE_WINDOW_H__
#define __FRACTALENGINE_WINDOW_H__

#include <cstdint>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <stb_image.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct GLFWwindow;
struct GLFWmonitor;

namespace Core
{
	class Window final
	{
		glm::ivec2					m_size;

		GLFWmonitor*				m_monitor								= nullptr;
		
		void						Window_FullScreenMode					(GLFWwindow* window);

		void						Window_ErrorCallBack					(int error, const char* description);

		static void					Window_S_KeyCallback					(GLFWwindow* window, int key, 
																			int scancode, int action, int mods);
	public:
		glm::ivec2					Window_Size() const;

		GLFWwindow*					m_window								= nullptr;
		static const int32_t		kDEFAULT_WIDTH							= 800,
									kDEFAULT_HEIGHT							= 600;

		int							iconWidth, iconHeight, iconChannels;
		unsigned char*				iconPixels;

		explicit					Window(const glm::ivec2& size			= glm::ivec2(kDEFAULT_WIDTH, kDEFAULT_HEIGHT));
		~Window();

		bool						Window_SwapBuffers();
	};
}
#endif	//__FRACTAL_ENGINE_WINDOW_H__
