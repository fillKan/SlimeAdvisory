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
	USER_INTERFACE->Render(pos, this, this->RenderRect);
}

void Image::SetRect(UI_RENDER_TYPE renderType, float fillAmount)
{
	switch (renderType)
	{
	case UI_RENDER_TYPE::DECREASEBOX_UP:
		break;

	case UI_RENDER_TYPE::DECREASEBOX_DOWN:
		break;

	case UI_RENDER_TYPE::DECREASEBOX_LEFT:
		break;

	case UI_RENDER_TYPE::DECREASEBOX_RIGHT:
		break;

	default:
		this->RenderRect = { 0,0,0,0 };
		break;
	}
}

void UserInterface::Render(Vector2 pos, Image* image, RECT renderingRECT)
{
	Matrix16 matrix;

	if (image->BackImage)
	{
		D3DXMatrixAffineTransformation2D(&matrix, 1.0f, nullptr, 1.f, &pos);

		IMAGE->GetSprite()->SetTransform(&matrix);
		IMAGE->GetSprite()->Draw(image->BackImage->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255,255,255));
	}
	if (image->FillImage)
	{
		IMAGE->GetSprite()->Draw(image->BackImage->pTexture, &renderingRECT, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
	if (image->EdgeImage)
	{
		IMAGE->GetSprite()->Draw(image->BackImage->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}
