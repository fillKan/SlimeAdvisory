#include "DXUT.h"
#include "MBHealthBar.h"

MBHealthBar::MBHealthBar() : UI(UI_RENDER_TYPE::DECREASEBOX_SIDE)
{
}

MBHealthBar::~MBHealthBar()
{
}

void MBHealthBar::Init()
{
	mImage.BackImage = IMAGE->AddImage("boss_hp_empty", "./image/UI/MBossHP/boss_hp_empty.png");
	mImage.FillImage = IMAGE->AddImage("boss_hp", "./image/UI/MBossHP/boss_hp.png");
	mImage.EdgeImage = IMAGE->AddImage("boss_icon", "./image/UI/MBossHP/boss_icon.png");

	mSumCURHP = 0.f;

	mImage.FillImageOffset = Vector2(82, 44);
}

void MBHealthBar::Update()
{
	mSumCURHP = 0.f;

	Object** findBoss = OBJECT->FindBosses();

	for (int i = 0; i < MBOSS_COUNT; ++i)
	{
		if (findBoss[i] != nullptr)
		{
			mSumCURHP += findBoss[i]->CURHealth;
		}
	}
	mFillAmount = mSumCURHP / (MBOSS_MAXHP * MBOSS_COUNT);

	mImage.SetRect(mRenderType, mFillAmount);

	mSumCURHP = 0.f;
}

void MBHealthBar::Render()
{
	mImage.Render(Vector2(550, 20));
}

void MBHealthBar::Release()
{
}
