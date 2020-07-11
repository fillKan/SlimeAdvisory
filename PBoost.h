#pragma once

enum class PLAY_STATE
{
	NONE, ING, BEGIN, END
};

class PBoost : public Object
{
public:
	 PBoost();
	~PBoost();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnCollisionEnter(Object* other) override;
	virtual void OnCollisionStay (Object* other) override;
	virtual void OnCollisionExit (Object* other) override;

private:
	Animation mIngAnim;
	Animation mBeginAnim;
	Animation mEndAnim;

	PLAY_STATE mCurrentState;

	Timer mTimer;
};

