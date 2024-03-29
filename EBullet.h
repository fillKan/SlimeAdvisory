#pragma once
class EBullet : public Object
{
public:
	 EBullet(Vector2 pos, Vector2 target, float speed);
	~EBullet();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

private:
	float mSpeed;

	Animation mAnimation;
};

