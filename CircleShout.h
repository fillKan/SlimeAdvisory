#pragma once
class CircleShout : public Skill
{
public:
	 CircleShout(float coolTime);
	~CircleShout();

	virtual void Update() override;
	virtual void Render() override;

	virtual void CastSkill() override;
};

