#pragma once
class PBulletBreak : public Particle
{
public:
	 PBulletBreak(Vector2 pos);
	~PBulletBreak();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual Particle* Instantiate(Vector2 pos) override;
};

