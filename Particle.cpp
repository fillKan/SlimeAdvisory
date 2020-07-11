#include "DXUT.h"
#include "Particle.h"

Particle::Particle(Vector2 pos) : Position(pos)
{
}

Particle::~Particle()
{
}

ParticleAdmin::ParticleAdmin()
{
}

ParticleAdmin::~ParticleAdmin()
{
	Release();
}

void ParticleAdmin::AddParticle(PARTICLES key, Particle* value)
{
	auto find = mLibrary.find(key);

	if (find == mLibrary.end())
	{
		mLibrary.insert(make_pair(key, value));
	}
}

Particle* ParticleAdmin::Instantiate(PARTICLES key, Vector2 pos)
{
	auto find = mLibrary.find(key);

	if (find != mLibrary.end())
	{
		Particle* particle = mLibrary[key]->Instantiate(pos);

		particle->Init();

		mParticles.emplace_back(particle);
		return particle;
	}
	return nullptr;
}

void ParticleAdmin::Update()
{
	for (auto iter = mParticles.begin(); iter != mParticles.end(); )
	{
		(*iter)->Update();

		if ((*iter)->CanDestroy())
		{
			SAFE_DELETE((*iter));

			iter = mParticles.erase(iter);

			continue;
		}
		iter++;
	}
}

void ParticleAdmin::Render()
{
	for (auto iter : mParticles)
	{
		iter->Render();
	}
}

void ParticleAdmin::Release()
{
	for (auto iter : mParticles)
	{
		SAFE_DELETE(iter);
	}
	mParticles.clear();

	for (auto iter : mLibrary)
	{
		SAFE_DELETE(iter.second);
	}
	mLibrary.clear();
}
