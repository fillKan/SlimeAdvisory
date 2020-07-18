#pragma once
class SkillGauge : public UI
{
public:
	 SkillGauge(Vector2 pos);
	~SkillGauge();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	void SkillLink(Skill* link);
	void SetImage(Texture* backImage, Texture* fillImage);

private:
	Vector2 mPosition;

	Skill* mLinkSkill;
};

