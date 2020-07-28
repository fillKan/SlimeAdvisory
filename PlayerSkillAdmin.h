#pragma once
class PlayerSkillAdmin : public Singleton<PlayerSkillAdmin>
{
public:

private:
	Skill* mPSkill[SELECT_MAX_SKILL] = { nullptr };
};
#define PLAYERSKILL PlayerSkillAdmin::Instance()