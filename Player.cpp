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

	mAnimation.AddFrame(IMAGE->AddImage("Skull1", "./image/Player/Skull1.png"));
	mAnimation.AddFrame(IMAGE->AddImage("Skull2", "./image/Player/Skull2.png"));
	mAnimation.AddFrame(IMAGE->AddImage("Skull3", "./image/Player/Skull3.png"));

	CircleRadius = 128.f;

	mSpeed = 4.5f;

	mTimer.SetTimer(0.1f, true);
}

void Player::Update()
{
	Velocity = ZERO;

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
