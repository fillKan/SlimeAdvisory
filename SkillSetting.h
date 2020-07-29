#pragma once

struct SkillButton
{
	Button* SkillBtn;

	Skill* LinkSkill;

	SkillButton(Button* skillButton) : SkillBtn(skillButton), mHasSelect(false)
	{
	}

	bool mHasSelect;

	char AttachKey;
};

struct SelectKeyImage
{
	Texture* Image;

	Vector2 Position;

	SelectKeyImage(Texture* image, Vector2 pos) : Image(image), Position(pos), HasLinkSkill(false)
	{
	}
	bool HasLinkSkill;
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

	SelectKeyImage Q, E;

	SkillButton* mBlankShout;
	SkillButton* mSteamPack;
	SkillButton* mGuideMissile;

	Texture* mBlankShoutText;
	Texture* mSteamPackText;
	Texture* mGuideMissileText;

	const D3DCOLOR UN_SELECTCOLOR = D3DCOLOR_XRGB(100, 100, 100);
	const D3DCOLOR	  SELECTCOLOR = D3DCOLOR_XRGB(255, 255, 255);

	const Vector2 LEFT_SIDE = Vector2(WINSIZEX * 0.35f, WINSIZEY * 0.45f);
	const Vector2 MIDDLE = Vector2(WINSIZEX * 0.5f, WINSIZEY * 0.45f);
	const Vector2 RIGHT_SIDE = Vector2(WINSIZEX * 0.65f, WINSIZEY * 0.45f);

};

