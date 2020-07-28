#pragma once

struct SkillButton
{
	Button* SkillBtn;

	SkillButton(Button* skillButton) : SkillBtn(skillButton), mHasSelect(false)
	{
	}

	bool mHasSelect;
};

class SkillSetting : public Scence
{
public:
	 SkillSetting();
	~SkillSetting();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

private:
	void SkillSelect(SkillButton* skillButton);

private:
	Texture* mHCloud[2];
	Texture* mMCloud[2];
	Texture* mSCloud[2];

	Vector2 mHCloudPos[2];
	Vector2 mMCloudPos[2];
	Vector2 mSCloudPos[2];

	Texture* mBackGround;

	const float   HUGE_CLOUD_SPEED = 1.4f;
	const float MIDDLE_CLOUD_SPEED = 0.8f;
	const float  SMALL_CLOUD_SPEED = 0.4f;

	Button* mExitButton;

	SkillButton* mBlankShout;
	SkillButton* mSteamPack;

	const D3DCOLOR UN_SELECTCOLOR = D3DCOLOR_XRGB(100, 100, 100);
	const D3DCOLOR	  SELECTCOLOR = D3DCOLOR_XRGB(255, 255, 255);
};

