#pragma once
class Blank : public Skill
{
public:
	 Blank(float coolTime);
	~Blank();

	virtual void Update() override;
	virtual void Render() override;

	virtual void CastSkill() override;
};

