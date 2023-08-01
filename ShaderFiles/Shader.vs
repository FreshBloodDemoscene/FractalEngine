#version 460 core
layout (location = 0) in vec2 aPos;

out vec2 vPos;

void main()
{
    vPos = aPos * 0.5 + vec2(0.5);
    vPos.y = 1.0 - vPos.y;
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
}