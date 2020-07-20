#include "DXUT.h"
#include "UI.h"

UI::UI(UI_RENDER_TYPE renderType) : mRenderType(renderType)
{
}

UI::~UI()
{
}

void Image::Render(Vector2 pos)
{
	USER_INTERFACE->UIRender(pos, this, this->RenderRect);
}

void Image::SetRect(UI_RENDER_TYPE renderType, float fillAmount)
{
	float decrease;

	UINT height = FillImage->info.Height;

	switch (renderType)
	{
	case UI_RENDER_TYPE::DECREASEBOX_UP:
		decrease = height - height * fillAmount;

		RenderRect = { 0, (LONG)(height), (LONG)FillImage->info.Width, (LONG)decrease };
		break;

	case UI_RENDER_TYPE::DECREASEBOX_DOWN:
		RenderRect = { 0, 0, (LONG)FillImage->info.Width, (LONG)(height * fillAmount) };
		break;

	case UI_RENDER_TYPE::DECREASEBOX_SIDE:
		RenderRect = { 0, 0, (LONG)(FillImage->info.Width * fillAmount), (LONG)height };
		break;

	default:
		RenderRect = { 0, 0, (LONG)FillImage->info.Width, (LONG)height };
		break;
	}
}

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
	Release();
}

void UserInterface::AddUI(UI* value)
{
	value->Init();

	mUIs.emplace_back(value);
}

void UserInterface::DelUI(UI* value)
{
	for (auto iter = mUIs.begin(); iter != mUIs.end(); iter++)
	{
		if ((*iter) == value)
		{
			SAFE_DELETE((*iter));

			mUIs.erase(iter); break;
		}
	}
}

void UserInterface::Update()
{
	for (auto iter : mUIs)
	{
		if (iter)
		{
			iter->Update();
		}
	}
}

void UserInterface::Render()
{
	for (auto iter : mUIs)
	{
		iter->Render();
	}
}

void UserInterface::UIRender(Vector2 pos, Image* image, RECT renderingRECT)
{
	Matrix16 matrix;

	RECT upRect = { 0, (LONG)image->FillImage->info.Height, (LONG)image->FillImage->info.Width, 0 };

	if (image->BackImage)
	{
		D3DXMatrixAffineTransformation2D(&matrix, 1.0f, nullptr, 0.f, &pos);

		IMAGE->GetSprite()->SetTransform(&matrix);

		if (image->RenderType == UI_RENDER_TYPE::DECREASEBOX_UP)
		{
			 IMAGE->GetSprite()->Draw(image->BackImage->pTexture, &upRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
		}		
		else IMAGE->GetSprite()->Draw(image->BackImage->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255,255,255));
	}
	if (image->FillImage)
	{
		IMAGE->GetSprite()->Draw(image->FillImage->pTexture, &renderingRECT, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
	if (image->EdgeImage != nullptr)
	{
		if (image->RenderType == UI_RENDER_TYPE::DECREASEBOX_UP)
		{
			 IMAGE->GetSprite()->Draw(image->EdgeImage->pTexture, &upRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
		}
		else IMAGE->GetSprite()->Draw(image->EdgeImage->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void UserInterface::Release()
{
	for (auto iter : mUIs)
	{
		SAFE_DELETE(iter);
	}
	mUIs.clear();
}
