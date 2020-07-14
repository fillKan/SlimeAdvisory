#include "DXUT.h"
#include "DummyEnemy.h"

#include "EBullet.h"

void DummyEnemy::Init()
{
	Name = "DummyEnemy";
	Tag = TAG::ENEMY;

	Position = Vector2(WINSIZEX, RANDOM(1, WINSIZEY));

	mAnimation.AddFrame("./image/Enemy/Normal/Attack/", "Monster_attack", 15);

	mSpeed = RANDOM(3, 4);

	CircleRadius = 32.f;

	mTimer.SetTimer(0.0f);
	mMinimalTimer.SetTimer(0.2f, true);

	HealthInit(ENEMY_DUMMY);
}

void DummyEnemy::Update()
{
	Velocity = ZERO;

	Position += (Velocity += LEFT * mSpeed);

	if (!CanFire)
	{
		if (mTimer.TimeOver())
		{
			mTimer.SetTimer(0.7f);

			CanFire = true;
		}
	}
	if (CanFire)
	{
		if (mMinimalTimer.TimeOver())
		{
			OBJECT->AddObject(new EBullet(Position, OBJECT->FindObject(TAG::PLAYER)->Position, 11.5f));

			ShootFire++;
		}
		if (ShootFire == 3)
		{
			ShootFire = 0;
			CanFire = false;
		}
	}
}

void DummyEnemy::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position);
}

void DummyEnemy::Release()
{
}

void DummyEnemy::OnCollisionEnter(Object* other)
{
}

void DummyEnemy::OnCollisionStay(Object* other)
{
}

void DummyEnemy::OnCollisionExit(Object* other)
{
}
