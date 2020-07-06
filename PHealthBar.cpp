#include "DXUT.h"
#include "PHealthBar.h"

PHealthBar::PHealthBar() : UI(UI_RENDER_TYPE::DECREASEBOX_UP)
{
}

PHealthBar::~PHealthBar()
{
}

void PHealthBar::Init()
{
	mFillAmount = 1.f;

	mImage.RenderType = mRenderType;

	mImage.BackImage = IMAGE->AddImage("PBHealthBar", "./image/UI/PBHealthBar.png");
	mImage.FillImage = IMAGE->AddImage("PHealthBar" ,  "./image/UI/PHealthBar.png");

	mImage.SetRect(mRenderType, mFillAmount);
}

void PHealthBar::Update()
{
	if (INPUT->GetKey('Q'))
	{
		mImage.SetRect(mRenderType, (mFillAmount -= 0.005f));
	}
	else if(INPUT->GetKey('E'))
	{
		mImage.SetRect(mRenderType, (mFillAmount += 0.005f));
	}
}

void PHealthBar::Render()
{
	mImage.Render(ONE * 90.f);
}

void PHealthBar::Release()
{
}
