#ifndef __FRACTAL_ENGINE_SYNCTRACKER_H__
#define __FRACTAL_ENGINE_SYNCTRACKER_H__

#include <exception>
#include <string>
#include <unordered_map>

#include <rocket/sync.h>
#include <soundTrack.h>

struct sync_device;
struct sync_track;

class SoundTrack;

namespace HighLevel
{
	class SyncTracker
	{
		double												m_row;
		double												m_time;
		sync_device* m_rocket;
		std::unordered_map<std::string, const sync_track*>	m_tracks;

	public:
		explicit SyncTracker();
		~SyncTracker() noexcept;

		void												SyncTracker_Update		(SoundTrack& SoundTrack);
		float												SyncTracker_FetchValue	(const std::string& name);
		float												SyncTracker_CurrentTime	();
	};
}
#endif	//__FRACTAL_ENGINE_SYNCTRACKER_H__
