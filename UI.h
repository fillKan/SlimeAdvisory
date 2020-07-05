#pragma once
enum class UI_RENDER_TYPE
{
	DECREASEBOX_UP,   DECREASEBOX_DOWN,
	DECREASEBOX_LEFT, DECREASEBOX_RIGHT
};

struct Image
{
	RECT RenderRect;

	Texture* FillImage;
	Texture* EdgeImage;
	Texture* BackImage;

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
public:
	void Render(Vector2 pos, Image* image, RECT renderingRECT);
};
#define USER_INTERFACE UserInterface::Instance()