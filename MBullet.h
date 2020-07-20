#pragma once
class MBullet : public Object
{
public:
	 MBullet(Vector2 pos, Vector2* target, float lifeTime);
	~MBullet();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

private:
	Vector2* mTarget;

	Timer mLifeTimer;
	Animation mAnimation;

	float mSpeed;
};

