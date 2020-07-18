#include "DXUT.h"
#include "PAttack.h"

PAttack::PAttack(Vector2 pos) : Particle(pos)
{
	mCurrentState = PLAY_STATE::NONE;
}

PAttack::~PAttack()
{
	Release();
}

void PAttack::Init()
{
	mAnimation.AddFrame("./image/Particle/PAttack/", "PlayerAttackEffect", 6);
	mAnimation.delay = 0.025f;

	mAttackBegin.AddFrame("./image/Particle/PAttackBegin/", "PlayerAttackStart", 3);
	mAttackBegin.delay = 0.05f;

	mAttackEnd.AddFrame("./image/Particle/PAttackEnd/", "PlayerAttackEnd", 3);
	mAttackEnd.delay = 0.05f;
}

void PAttack::Update()
{
	if (INPUT->GetKeyDown(ATTACKKEY) && mCurrentState != PLAY_STATE::BEGIN)
	{
		mCurrentState = PLAY_STATE::BEGIN;

		mAttackBegin.Rewind();

		mTimer.SetTimer(0.15f);
	}
	else if (INPUT->GetKey(ATTACKKEY))
	{
		mTimer.Update();

		if (mTimer.TimeOver())
		{
			mCurrentState = PLAY_STATE::ING;
		}
	}
	else if (INPUT->GetKeyUp(ATTACKKEY) && mCurrentState != PLAY_STATE::END)
	{
		mCurrentState = PLAY_STATE::END;

		mAttackEnd.Rewind();

		mTimer.SetTimer(0.15f);
	}
	if (mCurrentState == PLAY_STATE::END)
	{
		mTimer.Update();

		if (mTimer.TimeOver())
		{
			mCurrentState = PLAY_STATE::NONE;
		}		
	}
}

void PAttack::Render()
{
	switch (mCurrentState)
	{
	case PLAY_STATE::ING:
		IMAGE->CenterRender(mAnimation.Play(), Position);
		break;

	case PLAY_STATE::BEGIN:
		IMAGE->CenterRender(mAttackBegin.PlayOnce(), Position);
		break;

	case PLAY_STATE::END:
		IMAGE->CenterRender(mAttackEnd.PlayOnce(), Position);
		break;

	default:
		break;
	}
}

void PAttack::Release()
{
	mAttackBegin.Clear();

	mAttackEnd.Clear();
}

Particle* PAttack::Instantiate(Vector2 pos)
{
	return new PAttack(pos);
}
