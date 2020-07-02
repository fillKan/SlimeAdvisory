#include "DXUT.h"
#include "DummyEnemy.h"

void DummyEnemy::Init()
{
	Name = "DummyEnemy";
	Tag = TAG::ENEMY;

	Position = ZERO;

	mTexture = IMAGE->AddImage("DummyEnemy", "./image/DummyEnemy.png");
	collider.Init(ZERO, Vector2(mTexture->info.Width, mTexture->info.Height));

	CircleRadius = mTexture->info.Width * 0.5f;
}

void DummyEnemy::Update()
{
}

void DummyEnemy::Render()
{
	mTexture->Render(Position);
}

void DummyEnemy::Release()
{
}

void DummyEnemy::OnCollisionEnter(Object* other)
{
	if (other->Tag == TAG::PLAYER)
	{
		IsActive = false;
	}
}

void DummyEnemy::OnCollisionStay(Object* other)
{
}

void DummyEnemy::OnCollisionExit(Object* other)
{
	if (other->Tag == TAG::PLAYER)
	{
		IsActive = true;
	}
}
