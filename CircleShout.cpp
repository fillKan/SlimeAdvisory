#include "DXUT.h"
#include "CircleShout.h"

#include "PBullet.h"

CircleShout::CircleShout(float coolTime) : Skill(coolTime)
{
}

CircleShout::~CircleShout()
{
}

void CircleShout::Update()
{
	mTimer.Update();
}

void CircleShout::Render()
{
}

void CircleShout::CastSkill()
{
	if (mTimer.TimeOver())
	{
		Vector2 PPos = OBJECT->FindPlayer()->Position;
		Vector2 circlePoint;

		for (int i = 0; i < 360; i += 5)
		{
			circlePoint = Vector2(cosf(i), sinf(i));

			OBJECT->AddObject(new PBullet(PPos, circlePoint, atan2f(circlePoint.y, circlePoint.x)));
		}
	}
}
