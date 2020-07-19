#pragma once
class Skill abstract
{
public:
			 Skill(float coolTime);
	virtual ~Skill();

	virtual void Update() PURE;
	virtual void Render() PURE;

	virtual void CastSkill() PURE;

	void  SProgress(float percent)
	{
		mTimer.CurTime = percent * mTimer.EndTime;
	}
	virtual float GProgress() 
	{
		return mTimer.CurTime / mTimer.EndTime;
	}

protected:
	Timer mTimer;
};

