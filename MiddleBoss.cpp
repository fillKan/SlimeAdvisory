#include "DXUT.h"
#include "MiddleBoss.h"

#include "EBullet.h"
#include "DummyEnemy.h"
#include "MBullet.h"

MiddleBoss::MiddleBoss(Vector2 pos, Vector2 summonPoint, const string& name) : Object(), mSummonPoint(summonPoint)
{
	Position = pos;

	Name = name;

	mCURAction = MBOSS_PATTERN::APPER;

	mWaitingAction.SetTimer(0.f);
}

MiddleBoss::~MiddleBoss()
{
}

void MiddleBoss::Init()
{
	Tag = TAG::ENEMY;

	CircleRadius = 50.f;

	mSprite = IMAGE->AddImage("MiddleBoss", "./image/Enemy/MiddleBoss/MiddleBoss.png");

	HealthInit(550.f);

	mBombingPoint = Vector2(RANDOM(1, WINSIZEX - 1), RANDOM(1, WINSIZEY - 1));

}

void MiddleBoss::Update()
{
	int ScrOffset = SCREEN_OFFSET;

	Vector2 Pos;

	if (mCURAction == MBOSS_PATTERN::NONE)
	{
			mWaitingAction.Update();

		if (mWaitingAction.TimeOver())
		{
			int die = rand() % ((int)MBOSS_PATTERN::END - 1) + 1;

			mCURAction = (MBOSS_PATTERN)die;
		}
	}
	switch (mCURAction)
	{
	case MBOSS_PATTERN::APPER: 
		Apper();
		
		break;

	case MBOSS_PATTERN::BOMBING: 
		Bombing();
		
		break;

	case MBOSS_PATTERN::DASH: 
		Dash();
		
		break;

	default:
		break;
	}
}

void MiddleBoss::Render()
{
	mSprite->CenterRender(Position, Rotation);
}

void MiddleBoss::Release()
{
}

void MiddleBoss::OnCollisionEnter(Object* other)
{
}

void MiddleBoss::OnCollisionStay(Object* other)
{
}

void MiddleBoss::OnCollisionExit(Object* other)
{
}

void MiddleBoss::Apper()
{
	if (mLerpAmount == 0.f)
	{
		mInitPos = Position;
	}
	if (mLerpAmount < 1.f)
	{
		Position = Math::Lerp(mInitPos, mSummonPoint, (mLerpAmount += DELTA_TIME));
	}
	else
	{
		WaitForNextAcion(0.6f);

		mLerpAmount = 0.f;
	}
}

void MiddleBoss::Bombing()
{
	if (mLerpAmount == 0.f)
	{
		mInitPos = Position;
	}
	if (mLerpAmount < 1.f)
	{
		Position = Math::Lerp(mInitPos, mBombingPoint, (mLerpAmount += DELTA_TIME));
	}
	else
	{
		OBJECT->AddObject(new MBullet(Position, &(OBJECT->FindPlayer()->Position), 3.5f));

		WaitForNextAcion(1.3f);

		mBombingPoint = Vector2(RANDOM(1, WINSIZEX - 1), RANDOM(1, WINSIZEY - 1));

		mLerpAmount = 0.f;
	}
}

void MiddleBoss::Dash()
{	
	if (mLerpAmount == 0.f)
	{
		mDashPoint = OBJECT->FindPlayer()->Position;

		Direction = Math::AimVector(mDashPoint, Position);

		mInitPos = Position;
	}
	if (mLerpAmount < 1.f)
	{
		Position = Math::Lerp(mInitPos, mDashPoint + (Direction * 4.5f), mLerpAmount += DELTA_TIME);
	}
	else
	{
		mLerpAmount = 0.f;

		for (int i = 0; i < 360; i += 15)
		{
			Vector2 circlePoint = Vector2(cosf(i), sinf(i)) + Position;

			OBJECT->AddObject(new EBullet(Position, circlePoint, 330.f));
		}
		WaitForNextAcion(0.2f);
	}
}
