#pragma once
class PlayerSkillAdmin : public Singleton<PlayerSkillAdmin>
{
public:
	 PlayerSkillAdmin();
	~PlayerSkillAdmin();

	Skill* GetKeyAttachSkill(int keyCode);

private:
	Dictionary<char, Skill*> mPSkill;
};
#define PLAYERSKILL PlayerSkillAdmin::Instance()