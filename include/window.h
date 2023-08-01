#ifndef __FRACTALENGINE_WINDOW_H__
#define __FRACTALENGINE_WINDOW_H__

#include <cstdint>
#include <string>

#include <glm/glm.hpp>

struct GLFWwindow;
struct GLFWmonitor;

class Window final
{
	GLFWmonitor* m_monitor = nullptr;
	glm::ivec2   m_size;

	void FullScreenMode(GLFWwindow* window);

	void ErrorCallBack(int error, const char* description);

	static void s_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:	
	GLFWwindow* m_window = nullptr;
	static const int32_t kDEFAULT_WIDTH  = 800,
	                     kDEFAULT_HEIGHT = 600;

	explicit Window(const glm::ivec2& size = glm::ivec2(kDEFAULT_WIDTH, kDEFAULT_HEIGHT));
	~Window();

	bool SwapBuffers();
	glm::ivec2 Size() const;
};

#endif	//__FRACTAL_ENGINE_WINDOW_H__
