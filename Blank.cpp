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
		// To Do. . .
	}
}
