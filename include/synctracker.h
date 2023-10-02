#ifndef _FRACTAL_ENGINE_SYNCTRACKER__H_
#define _FRACTAL_ENGINE_SYNCTRACKER__H_

#include <iostream>

namespace Editor
{
	namespace SyncTracker
	{
		class EditorSyncTracker
		{
		public:
			explicit EditorSyncTracker();
			~EditorSyncTracker() noexcept;

			float FetchValue(const std::string& name);

		};
	}
}

#endif //_FRACTAL_ENGINE_SYNCTRACKER__H_
