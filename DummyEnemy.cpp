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

	mAnimation.AddFrame("./image/Enemy/Normal/Attack/", "Monster_attack", 15);

	mSpeed += RANDOM(4, 6) * 60;

	CircleRadius = 32.f;

	mTimer.SetTimer(0.0f);

	HealthInit(ENEMY_DUMMY);
}

void DummyEnemy::Update()
{
	Velocity = ZERO;

	Position += (Velocity += LEFT * mSpeed * DELTA_TIME);

	if (mTimer.TimeOver())
	{
		mTimer.SetTimer(0.9f, true);

		OBJECT->AddObject(new EBullet(Position, OBJECT->FindObject(TAG::PLAYER)->Position, 630.f));
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
