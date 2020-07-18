#pragma once
class PBullet : public Object
{
public:
	 PBullet(Vector2 pos, Vector2 dir, float rot);
	~PBullet();

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
};

