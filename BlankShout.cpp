#include "DXUT.h"
#include "BlankShout.h"

#include "PBullet.h"

BlankShout::BlankShout(float coolTime) : Skill(coolTime)
{
}

BlankShout::~BlankShout()
{
}

void BlankShout::Update()
{
	mTimer.Update();
}

void BlankShout::Render()
{
}

void BlankShout::CastSkill()
{
	if (mTimer.TimeOver())
	{
		deque<Object*> EBullets = OBJECT->FindObjects(TAG::EBULLET);

		for (auto iter : EBullets)
		{
			iter->IsDestory = true;

			PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, iter->Position);
		}

		Vector2 PPos = OBJECT->FindPlayer()->Position;
		Vector2 circlePoint;

		for (int i = 0; i < 360; i += 5)
		{
			circlePoint = Vector2(cosf(i), sinf(i));

			OBJECT->AddObject(new PBullet(PPos, circlePoint, atan2f(circlePoint.y, circlePoint.x)));
		}
	}
}
