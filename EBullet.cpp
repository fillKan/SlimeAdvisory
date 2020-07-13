#include "DXUT.h"
#include "EBullet.h"

#include "PBulletBreak.h"

EBullet::EBullet(Vector2 pos, Vector2 dir, float speed) : mSpeed(speed)
{
	Position  = pos;
	Direction = dir;
}

EBullet::~EBullet()
{
}

void EBullet::Init()
{
	Name = "EBullet";
	Tag = TAG::EBULLET;

	mAnimation.AddFrame("./image/Enemy/Bullet/", "MonsterBullet", 6);

	CircleRadius = 6.f;
}

void EBullet::Update()
{
	Velocity = ZERO;

	Position += (Velocity += mSpeed * Direction);
}

void EBullet::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position);
}

void EBullet::Release()
{
}

void EBullet::OnCollisionEnter(Object* other)
{
	if (other->Tag == TAG::PLAYER)
	{
		IsDestory = true;

		PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position);
	}
}

void EBullet::OnCollisionStay(Object* other)
{
}

void EBullet::OnCollisionExit(Object* other)
{
}
