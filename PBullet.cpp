#include "DXUT.h"
#include "PBullet.h"

#include "PBulletBreak.h"

PBullet::PBullet(Vector2 pos, Vector2 dir, float rot)
{
	Position = pos;

	Direction = dir;

	Rotation = rot;
}

PBullet::~PBullet()
{
}

void PBullet::Init()
{
	Name = "PBullet";
	Tag = TAG::PBULLET;


	mAnimation.AddFrame("./image/Player/Bullet/", "PlayerBullet", 6);

	CircleRadius = 15.f;

	mSpeed = 1100.f;
}

void PBullet::Update()
{
	Velocity = ZERO;

	Position += (Velocity += Direction * mSpeed * DELTA_TIME);
}

void PBullet::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position, Rotation);
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

		other->CURHealth -= PBULLET_DMG;
	}
}

void PBullet::OnCollisionStay(Object* other)
{
}

void PBullet::OnCollisionExit(Object* other)
{
}
