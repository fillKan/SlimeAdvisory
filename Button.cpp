#include "DXUT.h"
#include "Button.h"

Button::Button(Vector2 pos) : UI(UI_RENDER_TYPE::NONE), mPosition(pos)
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
		IMAGE->Render(mImage.EdgeImage, mPosition);
	}
	else if (mIsHighlight)
	{
		IMAGE->Render(mImage.FillImage, mPosition);
	}
	else
	{
		IMAGE->Render(mImage.BackImage, mPosition);
	}
}

void Button::Release()
{
}

void Button::SetButtonScale(RECT scale)
{
	mButtonScale = scale;
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
