#ifndef __FRACTALENGINE_ROCKETVALUES_H_
#define __FRACTALENGINE_ROCKETVALUES_H_

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>

#include <renderer.h>
#include <synctracker.h>
#include <textloader.h>

#define GLEW_STATIC
#include <GL/glew.h>

namespace HighLevel
{
	class RocketValues
	{
	public:
		explicit RocketValues();
		~RocketValues() noexcept;

		void			RocketValues_SetUp			(SyncTracker s, Graphics::Renderer& renderer);
	};
}
#endif	//__FRACTALENGINE_ROCKETVALUES_H_
