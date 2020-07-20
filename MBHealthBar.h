#pragma once
class MBHealthBar : public UI
{
public:
	 MBHealthBar();
	~MBHealthBar();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

private:
	float mFillAmount;

	float mSumCURHP;
};

