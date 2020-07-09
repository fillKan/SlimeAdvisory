#include "DXUT.h"
#include "PBullet.h"

void PBullet::Init()
{
	Name = "PBullet";
	Tag = TAG::PBULLET;

	Position = ZERO;

	mAnimation.AddFrame("./image/Player/Bullet/", "PlayerBullet", 6);

	CircleRadius = 8.f;

	mSpeed = 5.5f;
}

void PBullet::Update()
{
	Velocity = ZERO;

	Position += (Velocity += RIGHT * mSpeed);
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
	}
}

void PBullet::OnCollisionStay(Object* other)
{
}

void PBullet::OnCollisionExit(Object* other)
{
}
