#pragma once
class Banner : public Singleton<Banner>
{
public:
	 Banner();
	~Banner();

	void SetBanner(Texture* image, Vector2 pos);
	void SetButton(Button* button);

	void Update();
	void Render();

	void Close() { mIsShow = false; }
	void Show () { mIsShow =  true; }

private:
	bool mIsShow = false;

	Texture* mImage;
	Vector2  mPosition;
	Button* mButton;
};
#define BANNER Banner::Instance()
