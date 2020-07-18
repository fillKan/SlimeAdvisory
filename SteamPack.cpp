#include "DXUT.h"
#include "SteamPack.h"

SteamPack::SteamPack(float coolTime, float heal, float second) : Skill(coolTime), mHPS(heal/second), mSecond(second)
{
	mDurateTimer.SetTimer(second);

	mIsCast = false;
}

SteamPack::~SteamPack()
{
}

void SteamPack::Update()
{
	if (mIsCast)
	{
		float* CurrentHP = &(OBJECT->FindPlayer()->CURHealth);
		float*	   MaxHP = &(OBJECT->FindPlayer()->MAXHealth);

		mDurateTimer.Update();

		*CurrentHP += mHPS * DELTA_TIME;

		if (mDurateTimer.TimeOver() || *MaxHP <= *CurrentHP)
		{
			mIsCast = false;

			if (*MaxHP <= *CurrentHP)
			{
				*CurrentHP = *MaxHP;
			}
		}
	}
	else
	{
		mTimer.Update();
	}
}

void SteamPack::Render()
{
}

void SteamPack::CastSkill()
{
	if (mTimer.TimeOver())
	{
		mIsCast = true;
	}
}
