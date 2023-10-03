#include <renderer.h>

using namespace Graphics;

Renderer::Renderer(const Core::Window& window)
{
	float positions[] = {
		 1.0f,  1.0f,
		 1.0f, -1.0f,
		-1.0f, -1.0f,
		-1.0f,  1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	unsigned int EBO;
	glGenBuffers(1, &EBO);

	glCreateBuffers(1, &vertexBuffer);
	glNamedBufferStorage(vertexBuffer, 8 * sizeof(float), positions, 0);

	glCreateBuffers(1, &EBO);
	glNamedBufferStorage(EBO, 6 * sizeof(unsigned int), indices, 0);

	glCreateVertexArrays(1, &vao);
	glEnableVertexArrayAttrib(vao, 0);
	glVertexArrayVertexBuffer(vao, 0, vertexBuffer, 0, 2 * sizeof(float));
	glVertexArrayAttribBinding(vao, 0, 0);
	glVertexArrayAttribFormat(vao, 0, 2, GL_FLOAT, false, 0);
	glVertexArrayElementBuffer(vao, EBO);

	ReadAndCompileShader();
	Shader* shd = CreateShader(m_vertexShader, m_fragmentShader);
	if (shd)
		m_shader = *shd;
	glUseProgram(m_shader);

	glProgramUniform2f(m_shader, 0, float(window.Size().x), float(window.Size().y));
}

Renderer::~Renderer() noexcept
{
	glDeleteProgram(m_shader);
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(m_shader, "ourColor");

	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

Shader* Renderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return new Shader(program);
}

unsigned int Renderer::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

void Renderer::ReadAndCompileShader()
{
	if (fragmentShaderPath.empty())
	{
		fragmentPath = pfd::open_file("Select FragmentShader", ".", { "FragmentShaderFiles", "*.fs" }).result();
	}
	else
	{
		fragmentPath[0] = fragmentShaderPath;
	}

	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		if (!fragmentPath.empty())
		{
			for (auto const& filename : fragmentPath)
			{
				if (filename.empty())
				{
					fShaderFile.open(fragmentShaderPath);
				}
				fShaderFile.open(filename);
				fragmentShaderPath = filename;
			}

			vShaderFile.open(vertexShaderPath);

			std::stringstream vShaderStream, fShaderStream;

			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			vShaderFile.close();
			fShaderFile.close();

			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}	
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		__debugbreak();
	}

	m_vertexShader = vertexCode.c_str();
	m_fragmentShader = fragmentCode.c_str();

	UpdateShader();
}

void Renderer::UpdateShader()
{
	Shader* shd = CreateShader(m_vertexShader, m_fragmentShader);
	if (shd)
		m_shader = *shd;
	glUseProgram(m_shader);
}