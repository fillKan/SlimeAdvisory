#pragma once
class MiddleBoss : public Object
{
public:
	 MiddleBoss(Vector2 pos, Vector2 summonPoint);
	~MiddleBoss();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

private:
	void ThrowDie()
	{
		int die = RANDOM((int)MBOSS_PATTERN::APPER + 1, (int)MBOSS_PATTERN::END - 1);

		mCURPattern = (MBOSS_PATTERN)die;
	}

private:
	Texture* mSprite;

	Vector2 mSummonPoint;

	MBOSS_PATTERN mCURPattern;
};

