#include "DXUT.h"
#include "Image.h"

void Texture::Render(float x, float y, float rot)
{
	IMAGE->Render(this, x, y, rot);
}

void Texture::CenterRender(float x, float y, float rot)
{
	IMAGE->CenterRender(this, x, y, rot);
}

void Texture::Render(Vector2 pos, float rot)
{
	IMAGE->Render(this, pos, rot);
}

void Texture::CenterRender(Vector2 pos, float rot)
{
	IMAGE->CenterRender(this, pos, rot);
}

void ImageManager::Init()
{
	D3DXCreateSprite(DEVICE, &mSprite);
}

void ImageManager::Release()
{
	for (auto iter : mSprites)
	{
		iter.second->pTexture->Release();

		SAFE_DELETE(iter.second);
	}
	mSprites.clear();

	mSprite->Release();
}

ImageManager::ImageManager() : mSprite(nullptr)
{
	Init();
}

ImageManager::~ImageManager()
{
	Release();
}

Texture* ImageManager::AddImage(const string& key, const string& path)
{
	auto find = mSprites.find(key);

	if (find == mSprites.end())
	{
		LPDIRECT3DTEXTURE9 texture;
		D3DXIMAGE_INFO info;

		if (D3DXCreateTextureFromFileExA(DEVICE, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texture) == S_OK)
		{
			Texture* pText = new Texture(&texture, info);

			mSprites.insert(make_pair(key, pText));

			return pText;
		}
		return nullptr;
	}
	return find->second;
}

Texture* ImageManager::GetImage(const string& key)
{
	auto find = mSprites.find(key);

	if (find != mSprites.end()) return find->second;
	return nullptr;
}

void ImageManager::Render(Texture* texture, float x, float y, float rot)
{
	if (texture)
	{
		D3DXMATRIXA16 matrix;

		D3DXMatrixAffineTransformation2D(&matrix, 1.0f, nullptr, rot, &Vector2(x, y));

		mSprite->SetTransform(&matrix);
		mSprite->Draw(texture->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void ImageManager::CenterRender(Texture* texture, float x, float y, float rot)
{
	if (texture)
	{
		D3DXMATRIXA16 matrix;

		D3DXMatrixAffineTransformation2D(&matrix, 1.0f, nullptr, rot, &Vector2(x - texture->info.Width * 0.5f, y - texture->info.Height * 0.5f));

		mSprite->SetTransform(&matrix);
		mSprite->Draw(texture->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void ImageManager::Render(Texture* texture, Vector2 pos, float rot)
{
	if (texture)
	{
		D3DXMATRIXA16 matrix;

		D3DXMatrixAffineTransformation2D(&matrix, 1.0f, nullptr, rot, &pos);

		mSprite->SetTransform(&matrix);
		mSprite->Draw(texture->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void ImageManager::CenterRender(Texture* texture, Vector2 pos, float rot)
{
	if (texture)
	{
		D3DXMATRIXA16 matrix;

		D3DXMatrixAffineTransformation2D(&matrix, 1.0f, nullptr, rot, &Vector2(pos.x - texture->info.Width * 0.5f, pos.y - texture->info.Height * 0.5f));

		mSprite->SetTransform(&matrix);
		mSprite->Draw(texture->pTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void ImageManager::Begin()
{
	mSprite->Begin(1 << 4);
}

void ImageManager::End()
{
	mSprite->End();
}

void ImageManager::LostDevice()
{
	mSprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	mSprite->OnResetDevice();
}

void Animation::AddFrame(Texture* frame)
{
	if(frame) Frames.push_back(frame);
}

void Animation::Clear()
{
	Frames.clear();
}

Texture* Animation::Play()
{
	progress += DELTA_TIME;

	if (progress >= delay)
	{
		progress = 0.f;

		(currentFrame >= Frames.size() - 1) ? currentFrame = 0 : ++currentFrame;
	}
	return Frames[currentFrame];
}
