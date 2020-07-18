#pragma once

class PBoost;
#include "CircleShout.h"

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

	const Vector2 ATK_PARTICLE_OFFSET = Vector2(130.5f, 20.5f);
	const Vector2		 BOOST_OFFSET = Vector2(-90.f, 20.f);

	CircleShout mCircleShout;
};

