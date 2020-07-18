#pragma once
class DummyEnemy : public Object
{
public:
	 DummyEnemy(Vector2 pos, float addSpeed);
	~DummyEnemy();

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
};

