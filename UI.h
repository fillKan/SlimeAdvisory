#pragma once
enum class UI_RENDER_TYPE
{
	DECREASEBOX_UP,   DECREASEBOX_DOWN,
	DECREASEBOX_LEFT, DECREASEBOX_RIGHT
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

	RECT mRenderingRect;
};

struct Image
{
	RECT RenderRect;

	Texture* FillImage;
	Texture* EdgeImage;
	Texture* BackImage;

	void Render(Vector2 pos, float fillAmount = 1.f);
	void SetRect(UI_RENDER_TYPE renderType);
};

class UserInterface : public Singleton<UserInterface>
{

};
#define USER_INTERFACE UserInterface::Instance()