#include "DXUT.h"
#include "Blank.h"

Blank::Blank(float coolTime) : Skill(coolTime)
{
}

Blank::~Blank()
{
}

void Blank::Update()
{
	mTimer.Update();
}

void Blank::Render()
{
}

void Blank::CastSkill()
{
	if (mTimer.TimeOver())
	{
		deque<Object*> EBullets = OBJECT->FindObjects(TAG::EBULLET);

		for (auto iter : EBullets)
		{
			iter->IsDestory = true;

			PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, iter->Position);
		}
	}
}
