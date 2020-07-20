#include "DXUT.h"
#include "MBullet.h"

MBullet::MBullet(Vector2 pos, Vector2* target, float lifeTime) : mTarget(target)
{
	mLifeTimer.SetTimer(lifeTime);

	mSpeed = 50.f;
}

MBullet::~MBullet()
{
}

void MBullet::Init()
{
	Tag = TAG::EBULLET;

	mAnimation.AddFrame("./image/Enemy/MiddleBoss/Bullet/", "stage_1_boss_bullet_",6);

	CircleRadius = 30.f;
}

void MBullet::Update()
{
	mLifeTimer.Update();

	Direction = Math::AimVector(*mTarget, Position);
	Rotation = atan2f(Direction.y, Direction.x);

	Position += Direction * mSpeed * DELTA_TIME;

	if (mLifeTimer.TimeOver())
	{
		IsDestory = true;

		PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position);
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
	if (other->Tag == TAG::PLAYER)
	{
		IsDestory = true;

		PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position);
	}
}

void MBullet::OnCollisionStay(Object* other)
{
}

void MBullet::OnCollisionExit(Object* other)
{
}
