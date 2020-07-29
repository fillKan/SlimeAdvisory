#pragma once
class Button : public UI
{
public:
	 Button(Vector2 pos);
	~Button();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	void SetButtonScale(RECT scale);
	void SetRenderPara(Vector2 scale, D3DCOLOR color);

	void SetChangeImage(const string& default, const string& highlight, const string& onMouse);

	Vector2 GPosition() { return mPosition; }

	bool OnClick();
	bool OnPress();
	bool OnMouse();

	bool TakeOff();

private:
	RECT mButtonScale;

	Vector2 mCursorPos;
	Vector2 mPosition;

	Vector2 mScale;
	D3DCOLOR mColor;

	bool mIsHighlight = false;
	bool mIsPrevClick = false;
	bool mIsCrntClick = false;
};

