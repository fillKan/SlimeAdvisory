#include "DXUT.h"
#include "PlayerSkillAdmin.h"

#include "BlankShout.h"
#include "SteamPack.h"

PlayerSkillAdmin::PlayerSkillAdmin()
{
	// 기본 스킬 셋팅
	mPSkill.insert(make_pair('Q', new BlankShout(BLANKSHOUT_COOL)));

	mPSkill.insert(make_pair('E', new SteamPack(STEAMPACK_COOL, STEAMPACK_HEAL, STEAMPACK_DURATE)));
}

PlayerSkillAdmin::~PlayerSkillAdmin()
{
	for (auto iter : mPSkill)
	{
		SAFE_DELETE(iter.second);
	}
	mPSkill.clear();
}

Skill* PlayerSkillAdmin::GetKeyAttachSkill(int keyCode)
{
	auto find = mPSkill.find(keyCode);

	if (find != mPSkill.end())
	{
		return find->second;
	}
	return nullptr;
}

void PlayerSkillAdmin::SetKeyAttachSkill(int keyCode, Skill* attachSkill)
{
	if (!mPSkill.insert(make_pair(keyCode, attachSkill)).second)
	{
		SAFE_DELETE(mPSkill.find(keyCode)->second);

		mPSkill.find(keyCode)->second = attachSkill;
	}
}
