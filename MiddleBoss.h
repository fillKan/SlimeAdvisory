#pragma once
class MiddleBoss : public Object
{
public:
	 MiddleBoss(Vector2 pos);
	~MiddleBoss();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

private:
	Texture* mSprite;
};

