#include "DXUT.h"
#include "PBullet.h"

#include "PBulletBreak.h"

void PBullet::Init()
{
	Name = "PBullet";
	Tag = TAG::PBULLET;

	Position = ZERO;

	mAnimation.AddFrame("./image/Player/Bullet/", "PlayerBullet", 6);

	CircleRadius = 8.f;

	mSpeed = 7.5f;
}

void PBullet::Update()
{
	Velocity = ZERO;

	Direction = Math::AimVector(INPUT->CursorPos(), Position);

	Position += (Velocity += Direction * mSpeed);
}

void PBullet::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position);
}

void PBullet::Release()
{
}

void PBullet::OnCollisionEnter(Object* other)
{
	if (other->Tag == TAG::ENEMY)
	{
		IsDestory = true;

		PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position);
	}
}

void PBullet::OnCollisionStay(Object* other)
{
}

void PBullet::OnCollisionExit(Object* other)
{
}
