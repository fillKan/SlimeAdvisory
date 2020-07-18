#include "DXUT.h"
#include "Skill.h"

Skill::Skill(float coolTime)
{
	mTimer.SetTimer(coolTime, true);
}

Skill::~Skill()
{
}
