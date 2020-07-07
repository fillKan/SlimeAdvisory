#include "DXUT.h"
#include "DummyEnemy.h"

void DummyEnemy::Init()
{
	Name = "DummyEnemy";
	Tag = TAG::ENEMY;

	Position = Vector2(WINSIZEX, RANDOM(1, WINSIZEY));

	mAnimation.AddFrame(IMAGE->AddImage("DummyEnemy1", "./image/DummyEnemy/Skull_enemy1.png"));
	mAnimation.AddFrame(IMAGE->AddImage("DummyEnemy2", "./image/DummyEnemy/Skull_enemy2.png"));
	mAnimation.AddFrame(IMAGE->AddImage("DummyEnemy3", "./image/DummyEnemy/Skull_enemy3.png"));

	mSpeed = 2 + (RANDOM(1, 5) * 0.1f);

	CircleRadius = 64.f;
}

void DummyEnemy::Update()
{
	Velocity = ZERO;

	Position += (Velocity += LEFT * mSpeed);
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
	if (other->Tag == TAG::PLAYER)
	{
		IsDestory = true;
	}
}
