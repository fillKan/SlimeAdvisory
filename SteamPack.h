#pragma once
class SteamPack : public Skill
{
public:
	 SteamPack(float coolTime, float heal, float second);
	~SteamPack();

	virtual void Update() override;
	virtual void Render() override;

	virtual void CastSkill() override;

private:
	bool mIsCast;

	float mHPS;
	float mSecond;

	Timer mDurateTimer;
};

