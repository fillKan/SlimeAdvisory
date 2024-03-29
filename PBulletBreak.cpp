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
	if (RANDOM(0, 1) == 1)
	{
		mAnimation.SetFrame("./image/Particle/PBulletBreak/", "ExplosiveEffect1_", 9);
	}
	else
	{
		mAnimation.SetFrame("./image/Particle/PBulletBreak2/", "ExplosiveEffect2_", 9);
	}

	mTimer.SetTimer(0.9f);
}

void PBulletBreak::Update()
{
	mTimer.Update();

	mCanDestroy = mTimer.TimeOver();
}

void PBulletBreak::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position);
}

void PBulletBreak::Release()
{
	mAnimation.Clear();
}

Particle* PBulletBreak::Instantiate(Vector2 pos)
{
	return new PBulletBreak(pos);
}
