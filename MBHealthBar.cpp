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
}

void MBHealthBar::Update()
{
	char name[8];
	Object* findBoss;

	for (int i = 1; i <= 3; ++i)
	{
		sprintf(name, "MBoss%d", i);
		
		findBoss = OBJECT->FindObject(name);

		if (findBoss != nullptr)
		{
			mSumCURHP += findBoss->CURHealth;
		}
	}
	mFillAmount = mSumCURHP / (MBOSS_MAXHP * 3);

	mImage.RenderRect = { 1, 43, (LONG)(470 * mFillAmount), 91 };

	mSumCURHP = 0.f;
}

void MBHealthBar::Render()
{
	mImage.Render(Vector2(400, 200));
}

void MBHealthBar::Release()
{
}
