#include "DXUT.h"
#include "Timer.h"

void Timer::SetTimer(float end, bool isLoop)
{
	CurTime = 0.f;
	EndTime = end;

	IsLoop = isLoop;
	IsActive = true;
}

bool Timer::TimeOver()
{
	if (IsActive)
	{
		CurTime += DELTA_TIME;

		if (CurTime >= EndTime)
		{
			if (IsLoop) CurTime = 0.f;

			else IsActive = false;

			return true;
		}
	}
	return false;
}
