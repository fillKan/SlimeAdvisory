#pragma once
enum class UI_RENDER_TYPE
{
	DECREASEBOX_UP, DECREASEBOX_DOWN, DECREASEBOX_SIDE, NONE
};

struct Image
{
	RECT RenderRect;

	Texture* FillImage = nullptr;
	Texture* EdgeImage = nullptr;
	Texture* BackImage = nullptr;

	UI_RENDER_TYPE RenderType = UI_RENDER_TYPE::NONE;

	void Render(Vector2 pos);

	void SetRect(UI_RENDER_TYPE renderType, float fillAmount);
};

class UI abstract
{
public:
			 UI(UI_RENDER_TYPE renderType);
	virtual ~UI();

	virtual void Init   () PURE;
	virtual void Update () PURE;
	virtual void Render () PURE;
	virtual void Release() PURE;

protected:
	UI_RENDER_TYPE mRenderType;

	Image mImage;
};

class UserInterface : public Singleton<UserInterface>
{
private:
	vector<UI*> mUIs;

public:
	 UserInterface();
	~UserInterface();

	void AddUI(UI* value);
	void DelUI(UI* value);

	void Update();
	void Render();
	void UIRender(Vector2 pos, Image* image, RECT renderingRECT = RECT{ 0,0,0,0 });
	void Release();
};
#define USER_INTERFACE UserInterface::Instance()