#ifndef __FRACTAL_ENGINE_SOUNDTRACK_H__
#define __FRACTAL_ENGINE_SOUNDTRACK_H__

#include <iostream>

#include "bass.h"
#include <rocket/sync.h>

#pragma comment(lib, "bass.lib")

namespace HighLevel
{
	class SoundTrack
	{
	public:
		explicit SoundTrack();
		~SoundTrack();

		void PlayMusic				(std::string musicPath);
		static void* getFile		(std::string* file);

		static void ms_Pause		(void* d, int flag);
		static void ms_SetRow		(void* d, int row);
		static int  ms_IsPlaying	(void* d);

		HSTREAM						m_streamHandle;

		static sync_cb				s_syncLink;

		double CurrentRow() const;
		double CurrentTime() const;

		const float					tempo = 150.0f;

#define								ROWS_PER_BEAT (8.0)
		const double				m_rowRate = (tempo / 60.0) * ROWS_PER_BEAT;


	};
}
#endif	//__FRACTAL_ENGINE_WINDOW_H__



