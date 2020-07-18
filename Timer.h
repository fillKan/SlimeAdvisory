#pragma once
class Timer
{
public:
	float CurTime;
	float EndTime;

	bool IsLoop;

public:
	void Update();

	void SetTimer(float end, bool isLoop = false);
	bool TimeOver();
};

