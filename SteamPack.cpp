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
		mDurateTimer.Update();

		OBJECT->FindPlayer()->CURHealth += mHPS * DELTA_TIME;

		if (mDurateTimer.TimeOver())
		{
			mIsCast = false;
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
