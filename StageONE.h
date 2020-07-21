#pragma once
#include "PHealthBar.h"

#include "MiddleBoss.h"

class StageONE : public Scence
{
public:
	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

private:

	Timer mEnemySpawnTimer;

	Texture* mBackGround;

	Texture* mHCloud[2];
	Texture* mMCloud[2];
	Texture* mSCloud[2];

	Vector2 mHCloudPos[2];
	Vector2 mMCloudPos[2];
	Vector2 mSCloudPos[2];

	const float   HUGE_CLOUD_SPEED = 1.4f;
	const float MIDDLE_CLOUD_SPEED = 0.8f;
	const float  SMALL_CLOUD_SPEED = 0.4f;

	MiddleBoss* mMiddleBoss;
	bool mHasSummonMBoss = false;

	const D3DCOLOR BOSS_FIGHT_COLOR = D3DCOLOR_XRGB(255,  86, 135);
	float R, G, B;
	float mColorLerpAmount = 0.f;
};

