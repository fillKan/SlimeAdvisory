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
	mBeginAnim.delay = 0.05f;

	mIngAnim.AddFrame("./image/Player/Boost/Ing/", "PlayerAttackBoost", 12);
	mIngAnim.delay = 0.025f;

	mEndAnim.AddFrame("./image/Player/Boost/End/", "PlayerAttackEnd", 3);
	mEndAnim.delay = 0.05f;

	mCurrentState = PLAY_STATE::NONE;
}

void PBoost::Update()
{
	if (INPUT->GetKeyDown(ATTACKKEY))
	{
		mCurrentState = PLAY_STATE::BEGIN;

		mTimer.SetTimer(0.15f);
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

		mTimer.SetTimer(0.15f);
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
		IMAGE->CenterRender(mBeginAnim.Play(), Position);
		break;

	case PLAY_STATE::END:
		IMAGE->CenterRender(mEndAnim.Play(), Position);
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
