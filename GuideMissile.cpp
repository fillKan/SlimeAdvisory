#include "DXUT.h"
#include "GuideMissile.h"

#include "MBullet.h"

GuideMissile::GuideMissile(float coolTime, float damage, float lifeTime, float speed) : Skill(coolTime), mDamage(damage), mLifeTime(lifeTime), mSpeed(speed)
{
}

GuideMissile::~GuideMissile()
{
}

void GuideMissile::Update()
{
	mTimer.Update();
}

void GuideMissile::Render()
{
}

void GuideMissile::CastSkill()
{
	if (mTimer.TimeOver())
	{
		Vector2 playerPos = OBJECT->FindPlayer()->Position + Vector2(130.5f, 20.5f);

		Object* closestObject = OBJECT->Cloest(playerPos, TAG::ENEMY);

		if (closestObject != nullptr)
		{
			MBullet* missile = new MBullet(playerPos, closestObject, mLifeTime, mSpeed);

			missile->SetCollisionTarget(TAG::ENEMY, mDamage);

			OBJECT->AddObject(missile);

			missile->Tag = TAG::PBULLET;
		}
		else
		{
			mTimer.CurTime = mTimer.EndTime;
		}
	}
}
