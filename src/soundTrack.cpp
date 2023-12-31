#include <soundTrack.h>

using namespace HighLevel;

sync_cb SoundTrack::s_syncLink =
{
	SoundTrack::Ms_SetRow,
	SoundTrack::M_IsPlaying
};

SoundTrack::SoundTrack(){}

void SoundTrack::Initialisation()
{
	BOOL b = BASS_Init(-1, 44100, BASS_DEVICE_STEREO, 0, NULL);
	if (!b)
	{
		std::cout << BASS_ErrorGetCode() << std::endl;
		MessageBoxA(0, (LPCSTR)"BASS_Init could not be executed.", 0, MB_ICONERROR);
	}

	if (HIWORD(BASS_GetVersion()) != BASSVERSION)
	{
		MessageBoxA(0, (LPCSTR)"An incorrect version of BASS.DLL was loaded.", 0, MB_ICONERROR);
	}
}

SoundTrack::~SoundTrack(){}

void SoundTrack::PlayMusic(std::string musicPath)
{
	std::string filePath(musicPath);
	m_streamHandle = BASS_StreamCreateFile(false, filePath.data(), 0, 0, 0);
	BASS_ChannelPlay(m_streamHandle, true);
	timeNeeded = Length() * m_rowRate;
}

double SoundTrack::CurrentRow() const
{
	QWORD pos = BASS_ChannelGetPosition(m_streamHandle, BASS_POS_BYTE);
	double time = BASS_ChannelBytes2Seconds(m_streamHandle, pos);
	return time * m_rowRate;
}

double SoundTrack::Length() const
{
	QWORD len = BASS_ChannelGetLength(m_streamHandle, BASS_POS_BYTE);
	int time = BASS_ChannelBytes2Seconds(m_streamHandle, len);
	return time;
}

void SoundTrack::Pause()
{
	BASS_ChannelPause(m_streamHandle);
}


void SoundTrack::Unpause()
{
	BASS_ChannelPlay(m_streamHandle, FALSE);
}

void SoundTrack::Ms_SetRow(void* d, int row)
{
	SoundTrack* self = static_cast<SoundTrack*>(d);
	QWORD pos = BASS_ChannelSeconds2Bytes(self->m_streamHandle, row / self->m_rowRate);
	BASS_ChannelSetPosition(self->m_streamHandle, pos, BASS_POS_BYTE);
}

int SoundTrack::M_IsPlaying(void* d)
{
	SoundTrack* self = static_cast<SoundTrack*>(d);
	return BASS_ChannelIsActive(self->m_streamHandle) == BASS_ACTIVE_PLAYING;
}

void SoundTrack::Mute(bool mute)
{
	if (mute)
	{
		last_volume = volume;
		volume = 0;
		SetVolume();
	}
	else
	{
		volume = last_volume;
		SetVolume();
	}

}

void SoundTrack::GetVolume()
{
	BASS_ChannelGetAttribute(m_streamHandle, BASS_ATTRIB_VOL, &volume);
}

void SoundTrack::SetVolume()
{
	BASS_ChannelSetAttribute(m_streamHandle, BASS_ATTRIB_VOL, volume);
}
