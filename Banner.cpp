#include "DXUT.h"
#include "Banner.h"

Banner::Banner() : mButton(nullptr), mImage(nullptr), mPosition(ZERO)
{
}

Banner::~Banner()
{
}

void Banner::SetBanner(Texture* image, Vector2 pos)
{
	mImage = image; mPosition = pos;
}

void Banner::SetButton(Button* button)
{
	mButton = button;
}

void Banner::Update()
{

	if (mButton != nullptr)
	{
		mButton->Update();
	}

}

void Banner::Render()
{
	if (mIsShow)
	{
		if (mImage != nullptr)
		{
			mImage->Render(mPosition);
		}

		if (mButton != nullptr)
		{
			mButton->Render();
		}
	}
}
