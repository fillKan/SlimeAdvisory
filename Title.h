#pragma once
class Title : public Scence
{
public:
	 Title();
	~Title();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

private:

	Button* mStartButton;
	Button* mCreditButton;
	Button* mSettingButton;
	Button* mExitButton;

	Texture* mTitle;
	Texture* mBackGround;
	Texture* mCredit;
	Texture* mCreditWindow;

	Texture* mHCloud[2];
	Texture* mMCloud[2];
	Texture* mSCloud[2];

	Vector2 mHCloudPos[2];
	Vector2 mMCloudPos[2];
	Vector2 mSCloudPos[2];

	const float   HUGE_CLOUD_SPEED = 1.4f;
	const float MIDDLE_CLOUD_SPEED = 0.8f;
	const float  SMALL_CLOUD_SPEED = 0.4f;

	bool mCanShowCredit = false;
};

