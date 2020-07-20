#include "DXUT.h"
#include "MiddleBoss.h"

#include "EBullet.h"
#include "DummyEnemy.h"
#include "MBullet.h"

MiddleBoss::MiddleBoss(Vector2 pos, Vector2 summonPoint) : Object(), mSummonPoint(summonPoint)
{
	Position = pos;
	Velocity = pos;

	mCURPattern = MBOSS_PATTERN::APPER;

	mDashTimer.SetTimer(0.f);
	mNextPatternDelay.SetTimer(0.f);
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

	if (mCURPattern == MBOSS_PATTERN::NONE)
	{
		mNextPatternDelay.Update();

		if (mNextPatternDelay.TimeOver())
		{
			ThrowDie();
		}
	}
	switch (mCURPattern)
	{
	case MBOSS_PATTERN::APPER:
		Rotation = 0.f;

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
			StartTimer(0.4f);

			mLerpAmount = 0.f;
		}
		break;
	
	case MBOSS_PATTERN::BOMBING:

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

			StartTimer(1.3f);

			mBombingPoint = Vector2(RANDOM(1, WINSIZEX - 1), RANDOM(1, WINSIZEY - 1));

			mLerpAmount = 0.f;
		}
		break;

	case MBOSS_PATTERN::DASH:
		if (mDashTimer.EndTime == 0.f)
		{
			Direction = Math::AimVector(OBJECT->FindPlayer()->Position, Position);
			Rotation = Math::RadianAngle(OBJECT->FindPlayer()->Position, Position);

			mDashTimer.SetTimer(1.2f);
		}
		else if (!mDashTimer.TimeOver())
		{
			Velocity = (Direction * DELTA_TIME * 550.f) + Position;

			if (Velocity.x > WINSIZEX || Velocity.x < 0 ||
				Velocity.y > WINSIZEY || Velocity.y < 0)
			{
				// 돌진. 중단.
				mDashTimer.EndTime = 0.f;
				mDashTimer.CurTime = 0.f;

				StartTimer(0.2f);
			}
			else
			{
				Position = Velocity;
			}
			mDashTimer.Update();
		}
		else if (mDashTimer.TimeOver())
		{
			mDashTimer.EndTime = 0.f;

			for (int i = 0; i < 360; i += 15)
			{
				Vector2 circlePoint = Vector2(cosf(i), sinf(i)) + Position;

				OBJECT->AddObject(new EBullet(Position, circlePoint, 330.f));
			}
			StartTimer(0.2f);
		}
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
