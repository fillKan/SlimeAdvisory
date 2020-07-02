#include "DXUT.h"
#include "Player.h"

void Player::Init()
{
	Name = "Player";
	Tag = TAG::PLAYER;

	Position = Vector2(WINSIZEX / 2, WINSIZEY / 2);

	mTexture = IMAGE->AddImage("Player", "./image/Player.png");
	collider.Init(Vector2(-mTexture->info.Width / 2, -mTexture->info.Height / 2), Vector2(mTexture->info.Width / 2, mTexture->info.Height / 2));

	CircleRadius = mTexture->info.Width * 0.5f;

	mSpeed = 2.5f;

	CAMERA->mTraceObject = this;
	CAMERA->mIsTrace = true;
}

void Player::Update()
{
	Velocity = ZERO;

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
	mTexture->CenterRender(Position);
}

void Player::Release()
{
	CAMERA->mTraceObject = nullptr;
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
