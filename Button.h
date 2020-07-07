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

	void SetChangeImage(const string& default, const string& highlight, const string& onMouse);

	bool OnClick();

private:
	RECT mButtonScale;

	Vector2 mCursorPos;
	Vector2 mPosition;

	bool mIsHighlight = false;
	bool mIsClick	  = false;
};

