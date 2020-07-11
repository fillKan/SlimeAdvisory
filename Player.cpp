#include "DXUT.h"
#include "Player.h"

#include "PBullet.h"
#include "DummyEnemy.h"

Player::Player()
{
}

Player::~Player()
{
	mAnimation.Clear();
}

void Player::Init()
{
	Name = "Player";
	Tag = TAG::PLAYER;

	Position = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	mAttackPoint = (Position + Vector2(130.5f, 20.5f));

	mAnimation.AddFrame("./image/Player/Default/", "Player", 18);

	CircleRadius = 128.f;

	mSpeed = 4.5f;

	mTimer.SetTimer(0.25f, true);

	mAttackParticle = nullptr;

}

void Player::Update()
{
	Velocity = ZERO;

	if (INPUT->GetKeyDown(ATTACKKEY))
	{
		mAttackParticle = PARTICLE->Instantiate(PARTICLES::PATTACK, mAttackPoint);
	}

	if (INPUT->GetKey(VK_SPACE) && mTimer.TimeOver())
	{
		Object* bullet = new PBullet();
		
		OBJECT->AddObject(bullet);

		bullet->Position = mAttackPoint;
	}
	if (INPUT->GetKey(VK_UP))
	{
		Velocity = UP * mSpeed;
	}
	else if (INPUT->GetKey(VK_DOWN))
	{
		Velocity = DOWN * mSpeed;
	}
	if (INPUT->GetKey(VK_RIGHT))
	{
		Velocity = RIGHT * mSpeed;
	}
	else if (INPUT->GetKey(VK_LEFT))
	{
		Velocity = LEFT * mSpeed;
	}
	Position += Velocity;

	mAttackPoint = (Position + Vector2(130.5f, 20.5f));

	if (mAttackParticle)
	{
		mAttackParticle->Position = mAttackPoint;
	}
}

void Player::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position);
}

void Player::Release()
{
}

void Player::OnCollisionEnter(Object* other)
{
}

void Player::OnCollisionStay(Object* other)
{
}

void Player::OnCollisionExit(Object* other)
{
}
