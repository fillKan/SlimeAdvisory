#pragma once

class PBoost;

class Player : public Object
{
public:
	 Player();
	~Player();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

private:
	Animation mAnimation;

	float mSpeed;

	Timer mTimer;

	Vector2 mAttackPoint;

	Particle* mAttackParticle;
	PBoost* mBoostEffect;
};

