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

	mAnimation.AddFrame("./image/Player/Default/", "Player", 18);

	CircleRadius = 128.f;

	mSpeed = 4.5f;

	mTimer.SetTimer(0.25f, true);

}

void Player::Update()
{
	Velocity = ZERO;

	if (INPUT->GetKeyDown(ATTACKKEY))
	{
		PARTICLE->Instantiate(PARTICLES::PATTACK, Position + Vector2(20, 0));
	}

	if (INPUT->GetKey(VK_SPACE) && mTimer.TimeOver())
	{
		Object* bullet = new PBullet();
		
		OBJECT->AddObject(bullet);

		bullet->Position = Position;
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
