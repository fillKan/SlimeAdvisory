#pragma once

enum class PLAYTYPE
{
	SFX, BGM, NONE
};

class Sound : public Singleton<Sound>
{
private:
	Dictionary<string, string> mSounds;

public:
	void AddSound(const string& key, const string& path);
	void PlaySound(const string& key, PLAYTYPE type);
};
#define SOUND Sound::Instance()
