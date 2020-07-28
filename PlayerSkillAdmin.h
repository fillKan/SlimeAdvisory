#pragma once
class PlayerSkillAdmin : public Singleton<PlayerSkillAdmin>
{
public:
	 PlayerSkillAdmin();
	~PlayerSkillAdmin();

	Skill* GetKeyAttachSkill(int keyCode);
	int GetSkillAttachKey(Skill* skill);
	void SetKeyAttachSkill(int keyCode, Skill* attachSkill);

private:
	Dictionary<char, Skill*> mPSkill;
};
#define PLAYERSKILL PlayerSkillAdmin::Instance()