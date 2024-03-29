#pragma once
class MBullet : public Object
{
public:
	 MBullet(Vector2 pos, Object* target, float lifeTime, float speed);
	~MBullet();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

	void SetCollisionTarget(TAG targetTAG, float damage);

private:
	Object* mTarget;

	Timer mLifeTimer;
	Animation mAnimation;

	TAG mTargetTAG;

	float mSpeed;
	float mDamage;
};

