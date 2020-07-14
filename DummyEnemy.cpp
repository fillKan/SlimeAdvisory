#include "DXUT.h"
#include "DummyEnemy.h"

#include "EBullet.h"

void DummyEnemy::Init()
{
	Name = "DummyEnemy";
	Tag = TAG::ENEMY;

	Position = Vector2(WINSIZEX, RANDOM(1, WINSIZEY));

	mAnimation.AddFrame("./image/Enemy/Normal/Attack/", "Monster_attack", 15);

	mSpeed = 2 + (RANDOM(1, 5) * 0.1f);

	CircleRadius = 32.f;

	mTimer.SetTimer(0.0f);
	mMinimalTimer.SetTimer(0.2f, true);
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
			OBJECT->AddObject(new EBullet(Position, LEFT, 11.5f));

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
	if (other->Tag == TAG::PBULLET)
	{
		IsDestory = true;
	}
}

void DummyEnemy::OnCollisionStay(Object* other)
{
}

void DummyEnemy::OnCollisionExit(Object* other)
{
}
