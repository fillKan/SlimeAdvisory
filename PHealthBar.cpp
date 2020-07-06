#include "DXUT.h"
#include "PHealthBar.h"

PHealthBar::PHealthBar() : UI(UI_RENDER_TYPE::DECREASEBOX_RIGHT)
{
}

PHealthBar::~PHealthBar()
{
}

void PHealthBar::Init()
{
	mFillAmount = 1.f;

	mImage.BackImage = IMAGE->AddImage("PBHealthBar", "./image/UI/PBHealthBar.png");
	mImage.FillImage = IMAGE->AddImage("PHealthBar" ,  "./image/UI/PHealthBar.png");

	mImage.SetRect(mRenderType, mFillAmount);
}

void PHealthBar::Update()
{
	mImage.SetRect(mRenderType, (mFillAmount -= 0.02f));
}

void PHealthBar::Render()
{
	mImage.Render(ONE * 20.f);
}

void PHealthBar::Release()
{
}
