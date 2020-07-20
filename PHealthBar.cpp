#include "DXUT.h"
#include "PHealthBar.h"

PHealthBar::PHealthBar() : UI(UI_RENDER_TYPE::DECREASEBOX_SIDE), mPlayer(nullptr)
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

	mPlayer = OBJECT->FindPlayer();
}

void PHealthBar::Update()
{
	mFillAmount = (mPlayer->CURHealth / mPlayer->MAXHealth);

	mImage.SetRect(mRenderType, mFillAmount);
}

void PHealthBar::Render()
{
	mImage.Render(ONE * 55.f);
}

void PHealthBar::Release()
{
}
