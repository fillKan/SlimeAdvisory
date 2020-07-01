#pragma once
class Timer
{
public:
	float CurTime;
	float EndTime;

	bool IsLoop;
	bool IsActive;

public:
	void SetTimer(float end, bool isLoop = false);
	bool TimeOver();
};

