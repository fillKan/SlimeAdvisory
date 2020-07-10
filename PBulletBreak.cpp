#include "DXUT.h"
#include "PBulletBreak.h"

PBulletBreak::PBulletBreak(Vector2 pos) : Particle(pos)
{
}

PBulletBreak::~PBulletBreak()
{
	Release();
}

void PBulletBreak::Init()
{
	mAnimation.AddFrame("./image/Particle/PBulletBreak/", "ExplosiveEffect1_", 9);

	mTimer.SetTimer(0.9f);
}

void PBulletBreak::Update()
{
}

void PBulletBreak::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), mPosition);
}

void PBulletBreak::Release()
{
	mAnimation.Clear();
}

Particle* PBulletBreak::Instantiate(Vector2 pos)
{
	return new PBulletBreak(pos);
}
