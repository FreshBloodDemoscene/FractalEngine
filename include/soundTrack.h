#ifndef __FRACTAL_ENGINE_SOUNDTRACK_H__
#define __FRACTAL_ENGINE_SOUNDTRACK_H__

#include <iostream>
#include <string>

#include "bass.h"
#include <rocket/sync.h>

#pragma comment(lib, "bass.lib")

namespace HighLevel
{
	class SoundTrack
	{
	private:
		float					tempo	= 150.0f;
		bool					doOnce	= false;
	public:
		explicit SoundTrack();
		~SoundTrack() noexcept;

		void						PlayMusic	(std::string musicPath);

		static void					Ms_SetRow	(void* d, int row);
		static int					M_IsPlaying	(void* d);

		HSTREAM						m_streamHandle = NULL;

		void						Pause			();
		void						Unpause			();

		static sync_cb				s_syncLink;
		
		static void					Initialisation	();

		double						CurrentRow   () const;
		double						Length		() const;
		
		void						SetTempo(float _tempo){tempo = _tempo;}
		void						Mute(bool mute);

		void						GetVolume();
		void						SetVolume();

		float						volume = 1;
		float						last_volume;

#define								ROWS_PER_BEAT			(8.0)	

		const double				m_rowRate				= (tempo / 60.0) * ROWS_PER_BEAT;

		int							timeNeeded; 
	};
}
#endif	//__FRACTAL_ENGINE_WINDOW_H__



