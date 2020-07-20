#include "DXUT.h"
#include "DummyEnemy.h"

#include "EBullet.h"

DummyEnemy::DummyEnemy(Vector2 pos, float addSpeed) : Object()
{
	Position = pos;

	mSpeed = addSpeed * 60;
}

DummyEnemy::~DummyEnemy()
{
}

void DummyEnemy::Init()
{
	Name = "DummyEnemy";
	Tag = TAG::ENEMY;

	mAnimation.SetFrame("./image/Enemy/Normal/Attack/", "Monster_attack", 15);

	mSpeed += RANDOM(4, 6) * 60;

	CircleRadius = 32.f;

	mATKcool.SetTimer(0.9f, true);
	mATKcool.CurTime = 0.9f;

	HealthInit(ENEMY_DUMMY);
}

void DummyEnemy::Update()
{
	Position += LEFT * mSpeed * DELTA_TIME;

	mATKcool.Update();

	if (mATKcool.TimeOver())
	{
		Object* player = OBJECT->FindPlayer();

		if (player)
		{
			OBJECT->AddObject(new EBullet(Position, player->Position, 630.f));
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
