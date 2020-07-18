#include "DXUT.h"
#include "Timer.h"

void Timer::Update()
{
	float deltaTime = CurTime + DELTA_TIME;

	CurTime = (deltaTime > EndTime) ? EndTime : deltaTime;
}

void Timer::SetTimer(float end, bool isLoop)
{
	CurTime = 0.f;
	EndTime = end;

	IsLoop = isLoop;
}

bool Timer::TimeOver()
{
	if (CurTime >= EndTime)
	{
		if (IsLoop) CurTime = 0.f;

		return true;
	}
	return false;
}
