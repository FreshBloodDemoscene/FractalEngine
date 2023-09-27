#include <mediaPlayer.h>

using namespace HighLevel;

MediaPlayer::MediaPlayer()
{

}

MediaPlayer::~MediaPlayer()
{

}

void MediaPlayer::ChooseSong()
{
	auto songPath = pfd::open_file("Select a Song :", ".", { "MP3 and OGG files", "*.mp3 *.ogg" }).result();
	
	for (auto const& filename : songPath)
	{
		if (!filename.empty())
		{
			s.SoundTrack_PlayMusic(filename);
		}
	}
}