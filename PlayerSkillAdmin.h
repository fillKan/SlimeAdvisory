#pragma once

enum class SKILLS
{
	BLANKSHOUT, STEAMPACK, GUIDEMISSILE
};

class PlayerSkillAdmin : public Singleton<PlayerSkillAdmin>
{
public:
	 PlayerSkillAdmin();
	~PlayerSkillAdmin();

	Skill* GetSkill(SKILLS skill);

	Skill* GetKeyAttachSkill(int keyCode);
	int GetSkillAttachKey(Skill* skill);
	void SetKeyAttachSkill(int keyCode, Skill* attachSkill);

private:
	Dictionary<char, Skill*> mPSkill;
	Dictionary<char, Skill*> mPSkillLib;

	Skill *mBlankShout, *mSteamPack, *mGuideMissile;
};
#define PLAYERSKILL PlayerSkillAdmin::Instance()