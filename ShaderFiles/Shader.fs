#version 460 core
out vec4 FragColor;
  
in vec4 vertexColor; 

layout(location = 3) uniform vec3 LIGHT_COLOR;

void main()
{
	FragColor = vertexColor;
} 











