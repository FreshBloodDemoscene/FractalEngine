#include <shader.h>

using namespace Graphics;

Shader::Shader(unsigned int Shader)
    : m_shader(Shader)
{
    GLint numActiveUniform = 0;
}

Shader::operator unsigned int()
{
    return m_shader;
}