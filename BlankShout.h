#pragma once
class BlankShout : public Skill
{
public:
	 BlankShout(float coolTime);
	~BlankShout();

	virtual void Update() override;
	virtual void Render() override;

	virtual void CastSkill() override;
};

