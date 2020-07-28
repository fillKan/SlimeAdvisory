#include "DXUT.h"
#include "Button.h"

Button::Button(Vector2 pos) : UI(UI_RENDER_TYPE::NONE), mPosition(pos), mScale(ONE), mColor(D3DCOLOR_XRGB(255, 255, 255))
{
}

Button::~Button()
{
}

void Button::Init()
{
}

void Button::Update()
{
	mCursorPos = INPUT->CursorPos() - mPosition;

	mIsHighlight = (mCursorPos.x >= mButtonScale.left && mCursorPos.x <= mButtonScale.right &&
					mCursorPos.y >= mButtonScale.top  && mCursorPos.y <= mButtonScale.bottom);

	mIsPrevClick = mIsCrntClick;

	if (mIsHighlight && DXUTIsMouseButtonDown(VK_LBUTTON))
	{
		 mIsCrntClick = true;
	}
	else mIsCrntClick = false;
}

void Button::Render()
{
	if (mIsCrntClick)
	{
		IMAGE->CenterRender(mImage.EdgeImage, mPosition, mColor, mScale);
	}
	else if (mIsHighlight)
	{
		IMAGE->CenterRender(mImage.FillImage, mPosition, mColor, mScale);
	}
	else
	{
		IMAGE->CenterRender(mImage.BackImage, mPosition, mColor, mScale);
	}
}

void Button::Release()
{
}

void Button::SetButtonScale(RECT scale)
{
	mButtonScale = scale;
}

void Button::SetRenderPara(Vector2 scale, D3DCOLOR color)
{
	mScale = scale; mColor = color;
}

void Button::SetChangeImage(const string& default, const string& highlight, const string& onMouse)
{
	mImage.BackImage = IMAGE->AddImage(default, "./image/UI/Button/" + default + ".png");
	mImage.FillImage = IMAGE->AddImage(highlight, "./image/UI/Button/" + highlight + ".png");
	mImage.EdgeImage = IMAGE->AddImage(onMouse, "./image/UI/Button/" + onMouse + ".png");
}

bool Button::OnClick()
{
	return (mIsCrntClick && !mIsPrevClick);
}

bool Button::OnPress()
{
	return (mIsCrntClick && mIsPrevClick);
}

bool Button::TakeOff()
{
	return (!mIsCrntClick && mIsPrevClick);
}
