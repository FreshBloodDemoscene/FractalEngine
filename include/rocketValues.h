#ifndef __FRACTALENGINE_ROCKETVALUES_H_
#define __FRACTALENGINE_ROCKETVALUES_H_

#include <synctracker.h>
#include <textloader.h>

#include <iostream>
#include <renderer.h>
#include <stb_image.h>
#include <glm/gtc/matrix_transform.hpp>

namespace HighLevel
{
	class RocketValues
	{
	public:
		explicit RocketValues();
		~RocketValues();

		void setUpRocketValues(SyncTracker s, Graphics::Renderer& renderer);
	};
}
#endif	//__FRACTALENGINE_ROCKETVALUES_H_
