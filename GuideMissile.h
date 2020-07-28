#pragma once
class GuideMissile : public Skill
{
public:
	 GuideMissile(float coolTime, float damage, float lifeTime, float speed);
	~GuideMissile();

	virtual void Update() override;
	virtual void Render() override;
	virtual void CastSkill() override;

private:
	float mDamage, mLifeTime, mSpeed;
};

