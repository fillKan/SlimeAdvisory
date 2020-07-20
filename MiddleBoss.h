#pragma once
class MiddleBoss : public Object
{
public:
	 MiddleBoss(Vector2 pos, Vector2 summonPoint, const string& name);
	~MiddleBoss();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

private:
	void WaitForNextAcion(float sec)
	{
		mWaitingAction.SetTimer(sec);

		mCURAction = MBOSS_PATTERN::NONE;
	}

	void Apper();
	void Bombing();
	void Dash();

private:
	Texture* mSprite;

	Vector2 mSummonPoint;
	Vector2 mBombingPoint;
	Vector2 mDashPoint;

	MBOSS_PATTERN mCURAction;

	Timer mWaitingAction;

	float mLerpAmount = 0.f;
	Vector2 mInitPos;
};

