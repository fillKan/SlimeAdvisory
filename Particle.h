#pragma once
enum class PARTICLES
{
	PBULLET_BREAK
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

	bool CanDestroy() { return mCanDestroy; }

	virtual Particle* Instantiate(Vector2 pos) PURE;

protected:
	Timer mTimer;

	Vector2 mPosition;

	Animation mAnimation;

	bool mCanDestroy = false;
};

class ParticleAdmin : public Singleton<ParticleAdmin>
{
public:
	 ParticleAdmin();
	~ParticleAdmin();

	void AddParticle(PARTICLES key, Particle* value);

	void Instantiate(PARTICLES key, Vector2 pos);

	void Update ();
	void Render ();
	void Release();

private:
	Dictionary<PARTICLES, Particle*> mLibrary;

	list<Particle*> mParticles;
};
#define PARTICLE ParticleAdmin::Instance()