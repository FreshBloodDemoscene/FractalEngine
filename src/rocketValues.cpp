#include <rocketValues.h>

using namespace HighLevel;

RocketValues::RocketValues()
{
	color = glm::vec3(1.0f, 0.0f, 0.0f);
}

void RocketValues::RocketValues_SetUp(SyncTracker s, Graphics::Renderer& renderer)
{
	color.x = s.SyncTracker_FetchValue("color:X");
	color.y = s.SyncTracker_FetchValue("color:Y");
	color.z = s.SyncTracker_FetchValue("color:Z");

	glProgramUniform3f(renderer.m_shader, 3, color.x, color.y, color.z);
}

RocketValues::~RocketValues(){}