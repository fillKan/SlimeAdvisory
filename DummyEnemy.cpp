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

	mTimer.SetTimer(0.7f, true);
}

void DummyEnemy::Update()
{
	Velocity = ZERO;

	Position += (Velocity += LEFT * mSpeed);

	if (mTimer.TimeOver())
	{
		Vector2 Aim = Math::AimVector(OBJECT->FindObject(TAG::PLAYER)->Position, Position);

		OBJECT->AddObject(new EBullet(Position, Aim, 15.f));
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
