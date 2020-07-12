#include "DXUT.h"
#include "PBullet.h"

#include "PBulletBreak.h"

PBullet::PBullet(Vector2 pos)
{
	Position = pos;
}

PBullet::~PBullet()
{
}

void PBullet::Init()
{
	Name = "PBullet";
	Tag = TAG::PBULLET;


	mAnimation.AddFrame("./image/Player/Bullet/", "PlayerBullet", 6);

	Direction = Math::AimVector(INPUT->CursorPos(), Position);
	CircleRadius = 8.f;

	mSpeed = 9.5f;
}

void PBullet::Update()
{
	Velocity = ZERO;

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
