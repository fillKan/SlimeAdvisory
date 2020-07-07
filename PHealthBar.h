#pragma once
class PHealthBar : public UI
{
public:
	 PHealthBar();
	~PHealthBar();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

private:

	float mFillAmount;
};

