#include "DXUT.h"
#include "Particle.h"

Particle::Particle(Vector2 pos, float lifeTime) : mPosition(pos)
{
	mTimer.SetTimer(lifeTime);
}

Particle::~Particle()
{
}
