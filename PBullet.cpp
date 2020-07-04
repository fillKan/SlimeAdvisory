#include "DXUT.h"
#include "PBullet.h"

void PBullet::Init()
{
	Name = "PBullet";
	Tag = TAG::PBULLET;

	Position = ZERO;

	mTexture = IMAGE->AddImage("PBullet", "./image/PBullet.png");

	CircleRadius = 64.f;

	mSpeed = 5.5f;
}

void PBullet::Update()
{
	Velocity = ZERO;

	Position += (Velocity += RIGHT * mSpeed);
}

void PBullet::Render()
{
	mTexture->CenterRender(Position);
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
