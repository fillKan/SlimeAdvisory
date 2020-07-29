#include "DXUT.h"
#include "PlayerSkillAdmin.h"

#include "BlankShout.h"
#include "SteamPack.h"
#include "GuideMissile.h"

PlayerSkillAdmin::PlayerSkillAdmin()
{
	// 기본 스킬 셋팅
	mPSkillLib.insert(make_pair('Q', mBlankShout = new BlankShout(BLANKSHOUT_COOL)));

	mPSkillLib.insert(make_pair('E', mSteamPack = new SteamPack(STEAMPACK_COOL, STEAMPACK_HEAL, STEAMPACK_DURATE)));

	mPSkillLib.insert(make_pair('R', mGuideMissile = new GuideMissile(3.5f, 100, 5.5f, 8.5f)));

	mPSkill = mPSkillLib;
}

PlayerSkillAdmin::~PlayerSkillAdmin()
{
	for (auto iter : mPSkillLib)
	{
		SAFE_DELETE(iter.second);
	}
	mPSkillLib.clear();

	mPSkill.clear();
}

Skill* PlayerSkillAdmin::GetSkill(SKILLS skill)
{
	switch (skill)
	{
	case SKILLS::BLANKSHOUT:
		return mBlankShout;

	case SKILLS::STEAMPACK:
		return mSteamPack;

	case SKILLS::GUIDEMISSILE:
		return mGuideMissile;
	}
	return nullptr;
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

int PlayerSkillAdmin::GetSkillAttachKey(Skill* skill)
{
	for (auto iter : mPSkill)
	{
		if (iter.second == skill)
		{
			return iter.first;
		}
	}
	return -1;
}

void PlayerSkillAdmin::SetKeyAttachSkill(int keyCode, Skill* attachSkill)
{
	auto find = mPSkill.find(keyCode);

	if (find != mPSkill.end())
	{
		find->second = attachSkill;
	}
}
