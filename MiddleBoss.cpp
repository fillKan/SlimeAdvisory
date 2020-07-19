#include "DXUT.h"
#include "MiddleBoss.h"

#include "EBullet.h"

MiddleBoss::MiddleBoss(Vector2 pos, Vector2 summonPoint) : Object(), mSummonPoint(summonPoint)
{
	Position = pos;
	Velocity = pos;

	mCURPattern = MBOSS_PATTERN::APPER;

	mDashTimer.SetTimer(0.f);
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
}

void MiddleBoss::Update()
{
	switch (mCURPattern)
	{
	case MBOSS_PATTERN::APPER:
		Rotation = 0.f;

		CURHealth = (CURHealth + 20.f > MAXHealth) ? MAXHealth : CURHealth + 20.f;

		if ((int)Velocity.x > (int)mSummonPoint.x)
		{
			Math::Lerp(&Velocity, Position, mSummonPoint, 1.5f);

			Position = Velocity;
		}
		else
		{
			ThrowDie();
		}
		break;
	case MBOSS_PATTERN::AAA:
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

				ThrowDie();
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
			ThrowDie();
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
