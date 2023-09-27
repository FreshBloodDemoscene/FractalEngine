#ifndef __FRACTAL_ENGINE_MEDIAPLAYER_H__
#define __FRACTAL_ENGINE_MEDIAPLAYER_H__

#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

#include <portable-file-dialogs.h>
#include <soundTrack.h>

#include <bass.h>

namespace HighLevel
{
	class MediaPlayer
	{
		SoundTrack s;
	public:
		explicit MediaPlayer();
		~MediaPlayer() noexcept;

		void ChooseSong();
	};
}

#endif // !__FRACTAL_ENGINE_MEDIAPLAYER_H__

