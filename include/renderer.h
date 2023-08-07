#ifndef __FRACTAL_ENGINE_RENDERER_H__
#define __FRACTAL_ENGINE_RENDERER_H__

#include <cstdint>
#include <string>
#include <portable-file-dialogs.h>

namespace Core { class Window; }

namespace Graphics
{
	class Renderer final
	{
	public:
		uint32_t							vao;
		uint32_t							vertexBuffer;
		uint32_t							m_shader = 0;
		uint32_t							m_buffer = 0;

		float								positions[6];

		std::string							m_vertexShader;
		std::string							m_fragmentShader = "";
		std::string							fragmentShaderPath;
		std::string							vertexShaderPath = "ShaderFiles/Shader.vs";

		std::vector<std::string>			fragmentPath;

		void CompileShader();
		static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

		static unsigned int CompileShader(unsigned int type, const std::string& source);
		void UpdateShader();

		explicit Renderer(const Core::Window& window);
		~Renderer() noexcept;

		void Render();
	};
}
#endif	//__FRACTAL_ENGINE_RENDERER_H__
