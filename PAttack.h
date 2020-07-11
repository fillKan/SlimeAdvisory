#pragma once

enum class PLAY_STATE
{
	NONE, ING, BEGIN, END
};

class PAttack : public Particle
{
public:
	 PAttack(Vector2 pos);
	~PAttack();

	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual Particle* Instantiate(Vector2 pos) override;

private:

	Animation mAttackBegin;
	Animation mAttackEnd;

	PLAY_STATE mCurrentState;
};

