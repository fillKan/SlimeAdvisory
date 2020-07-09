#pragma once
class Particle abstract
{
public:
			 Particle(Vector2 pos, float lifeTime);
	virtual ~Particle();

	virtual void Init   () PURE;
	virtual void Update () PURE;
	virtual void Render () PURE;
	virtual void Release() PURE;

	bool CanDestroy() { return mTimer.TimeOver(); }

protected:
	Timer mTimer;

	Vector2 mPosition;

	Animation mAnimation;
};

