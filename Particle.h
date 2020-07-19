#pragma once
enum class PARTICLES
{
	PBULLET_BREAK, PATTACK
};

class Particle abstract
{
public:
			 Particle(Vector2 pos);
	virtual ~Particle();

	virtual void Init   () PURE;
	virtual void Update () PURE;
	virtual void Render () PURE;
	virtual void Release() PURE;

	void SetDestroy(bool isDestroy) { mCanDestroy = isDestroy; }

	bool CanDestroy() { return mCanDestroy; }

	virtual Particle* Instantiate(Vector2 pos) PURE;

public:
	Vector2 Position;

protected:
	Timer mTimer;

	Animation mAnimation;

	bool mCanDestroy = false;
};

class ParticleAdmin : public Singleton<ParticleAdmin>
{
public:
	 ParticleAdmin();
	~ParticleAdmin();

	void AddParticle(PARTICLES key, Particle* value);

	Particle* Instantiate(PARTICLES key, Vector2 pos);

	void Update ();
	void Render ();
	void Release();

private:
	Dictionary<PARTICLES, Particle*> mLibrary;

	list<Particle*> mParticles;
};
#define PARTICLE ParticleAdmin::Instance()