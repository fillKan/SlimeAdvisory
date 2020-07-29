#pragma once

struct Texture
{
	LPDIRECT3DTEXTURE9 pTexture;

	D3DXIMAGE_INFO info;

	Texture(LPDIRECT3DTEXTURE9* texture, D3DXIMAGE_INFO info)
		:pTexture(*texture), info(info)
	{
	}
	void	   Render(float x, float y, float rot = 0.0f);
	void CenterRender(float x, float y, float rot = 0.0f);

	void	   Render(Vector2 pos, float rot = 0.0f);
	void CenterRender(Vector2 pos, float rot = 0.0f);
};

struct Animation
{
	vector<Texture*> Frames;

	void SetFrame(const string& path, const string& name, int frame);
	void Clear();
	void Rewind() { currentFrame = 0; }

	Texture* Play();
	Texture* PlayOnce();

	unsigned currentFrame = 0;

	float delay = 0.1f;
	float progress = 0.0f;
};

class ImageManager : public Singleton<ImageManager>
{
private:
	void Init();
	void Release();

public:
	 ImageManager();
	~ImageManager();

	Texture* AddImage(const string& key, const string& path);
	Texture* GetImage(const string& key);

	void	   Render(Texture* texture, float x, float y, float rot = 0.0f);
	void CenterRender(Texture* texture, float x, float y, float rot = 0.0f);

	void	   Render(Texture* texture, Vector2 pos, float rot = 0.0f);
	void CenterRender(Texture* texture, Vector2 pos, float rot = 0.0f);

	void	   Render(Texture* texture, Vector2 pos, D3DCOLOR color);
	void CenterRender(Texture* texture, Vector2 pos, D3DCOLOR color);

	void	   Render(Texture* texture, Vector2 pos, D3DCOLOR color, Vector2 scale);
	void CenterRender(Texture* texture, Vector2 pos, D3DCOLOR color, Vector2 scale);

	LPD3DXSPRITE GetSprite() { return mSprite; }

	void Begin();
	void End();

	void  LostDevice();
	void ResetDevice();
private:
	LPD3DXSPRITE mSprite;

	Dictionary<string, Texture*> mSprites;
};
#define IMAGE ImageManager::Instance()
