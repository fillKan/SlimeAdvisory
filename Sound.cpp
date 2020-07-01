#include "DXUT.h"
#include "Sound.h"

void Sound::AddSound(const string& key, const string& path)
{
	auto find = mSounds.find(key);

	if (find == mSounds.end())
	{
		string name;
		name = "open ";
		name += path;
		name += " type mpegvideo alias A";

		mSounds.insert(make_pair(key, name));
	}
}

void Sound::PlaySound(const string& key, PLAYTYPE type)
{
	auto find = mSounds.find(key);

	if (find != mSounds.end())
	{
		if (type == PLAYTYPE::SFX)
		{
			sndPlaySound((LPCWSTR)find->second.c_str(), SND_ASYNC);
		}
		else if (type == PLAYTYPE::BGM)
		{
			mciSendString((LPCWSTR)find->second.c_str(), NULL, NULL, NULL);
			mciSendString(L"play A notify repeat", NULL, NULL, NULL);
		}
	}
}
