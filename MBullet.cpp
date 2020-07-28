#include "DXUT.h"
#include "MBullet.h"
#include "EBullet.h"
#include "PBullet.h"

MBullet::MBullet(Vector2 pos, Object* target, float lifeTime, float speed) : mTarget(target), mTargetTAG(TAG::PLAYER), mDamage(2), mSpeed(speed)
{
	Position = pos;

	mLifeTimer.SetTimer(lifeTime);

	mSpeed = 500.f;
}

MBullet::~MBullet()
{
}

void MBullet::Init()
{
	Tag = TAG::EBULLET;

	mAnimation.SetFrame("./image/Enemy/MiddleBoss/Bullet/", "stage_1_boss_bullet_",6);

	CircleRadius = 30.f;
}

void MBullet::Update()
{
	mLifeTimer.Update();

	if (mLifeTimer.TimeOver())
	{
		IsDestory = true;

		PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position);

		return;
	}

	if (!mTarget->IsDestory)
	{
		Direction = Math::AimVector(mTarget->Position, Position);

		Rotation = atan2f(Direction.y, Direction.x) - PI;

		Position += Direction * mSpeed * DELTA_TIME;
	}
	else
	{
		mTarget = OBJECT->Cloest(Position, TAG::ENEMY);

		if (mTarget == nullptr)
		{
			IsDestory = true;

			PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position);
		}
	}
}

void MBullet::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position, Rotation);
}

void MBullet::Release()
{
}

void MBullet::OnCollisionEnter(Object* other)
{
	if (other->Tag == mTargetTAG)
	{
		IsDestory = true;

		if (mTargetTAG == TAG::ENEMY)
		{
			int invoke = RANDOM(10, 15);

			for (int i = 0; i < invoke; ++i)
			{
				PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position + (Math::RandomCirclePoint(ZERO) * 185));
			}

			Vector2 circlePoint;

			PBullet* pBullet;

			for (int i = 0; i < 360; i += 10)
			{
				circlePoint = Vector2(cosf(i), sinf(i));

				pBullet = new PBullet(Position, circlePoint, atan2f(circlePoint.y, circlePoint.x),550.f);

				OBJECT->AddObject(pBullet);

			}
		}

		other->CURHealth -= mDamage;
	}
}

void MBullet::OnCollisionStay(Object* other)
{
}

void MBullet::OnCollisionExit(Object* other)
{
}

void MBullet::SetCollisionTarget(TAG targetTAG, float damage)
{
	mTargetTAG = targetTAG; mDamage = damage;
}
