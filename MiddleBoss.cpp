#include "DXUT.h"
#include "MiddleBoss.h"

#include "EBullet.h"
#include "DummyEnemy.h"

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

			mNextPatternDelay.EndTime = 0.f;
		}
	}
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
			StartTimer(0.4f);
		}
		break;
	case MBOSS_PATTERN::SUMMON_LACKEY:
		Pos = Vector2(WINSIZEX, RANDOM(ScrOffset, WINSIZEY - ScrOffset));

		switch (RANDOM(0, 3))
		{
		case 0:
			OBJECT->AddObject(new DummyEnemy(Pos + (DOWN * 80.f), 2.5f));
			OBJECT->AddObject(new DummyEnemy(Pos + (UP * 80.f), 2.5f));
			break;

		case 1:
			OBJECT->AddObject(new DummyEnemy(Pos, 4.f));
			break;

		default:
			OBJECT->AddObject(new DummyEnemy(Pos, 0.f));
			break;
		}
		StartTimer(0.8f);
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

				StartTimer(1.2f);
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
			StartTimer(0.5f);
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
