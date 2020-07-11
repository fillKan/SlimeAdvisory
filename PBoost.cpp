#include "DXUT.h"
#include "PBoost.h"

PBoost::PBoost()
{
}

PBoost::~PBoost()
{
	mBeginAnim.Clear();

	mIngAnim.Clear();

	mEndAnim.Clear();
}

void PBoost::Init()
{
	mBeginAnim.AddFrame("./image/Player/Boost/Begin/", "PlayerAttackBoostStart", 3);

	mIngAnim.AddFrame("./image/Player/Boost/Ing/", "PlayerAttackBoost", 12);

	mEndAnim.AddFrame("./image/Player/Boost/End/", "PlayerAttackBoostEnd", 3);

	mCurrentState = PLAY_STATE::NONE;
}

void PBoost::Update()
{
	if (INPUT->GetKeyDown(ATTACKKEY))
	{
		mCurrentState = PLAY_STATE::BEGIN;

		mBeginAnim.Rewind();

		mTimer.SetTimer(0.3f);
	}
	else if (INPUT->GetKey(ATTACKKEY))
	{
		if (mTimer.TimeOver())
		{
			mCurrentState = PLAY_STATE::ING;
		}
	}
	else if (INPUT->GetKeyUp(ATTACKKEY))
	{
		mCurrentState = PLAY_STATE::END;

		mEndAnim.Rewind();

		mTimer.SetTimer(0.3f);
	}
	if (mCurrentState == PLAY_STATE::END && mTimer.TimeOver())
	{
		mCurrentState = PLAY_STATE::NONE;
	}
}

void PBoost::Render()
{
	switch (mCurrentState)
	{
	case PLAY_STATE::ING:
		IMAGE->CenterRender(mIngAnim.Play(), Position);
		break;

	case PLAY_STATE::BEGIN:
		IMAGE->CenterRender(mBeginAnim.PlayOnce(), Position);
		break;

	case PLAY_STATE::END:
		IMAGE->CenterRender(mEndAnim.PlayOnce(), Position);
		break;

	default:
		break;
	}
}

void PBoost::Release()
{
}

void PBoost::OnCollisionEnter(Object* other)
{
}

void PBoost::OnCollisionStay(Object* other)
{
}

void PBoost::OnCollisionExit(Object* other)
{
}
