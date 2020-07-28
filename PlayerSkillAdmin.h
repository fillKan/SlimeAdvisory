#pragma once
class PlayerSkillAdmin : public Singleton<PlayerSkillAdmin>
{
public:
	 PlayerSkillAdmin();
	~PlayerSkillAdmin();

	Skill* GetKeyAttachSkill(int keyCode);
	void SetKeyAttachSkill(int keyCode, Skill* attachSkill);

private:
	Dictionary<char, Skill*> mPSkill;
};
#define PLAYERSKILL PlayerSkillAdmin::Instance()