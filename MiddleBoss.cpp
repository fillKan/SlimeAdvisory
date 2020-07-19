#include "DXUT.h"
#include "MiddleBoss.h"

MiddleBoss::MiddleBoss(Vector2 pos, Vector2 summonPoint) : Object(), mSummonPoint(summonPoint)
{
	Position = pos;
	Velocity = pos;
}

MiddleBoss::~MiddleBoss()
{
}

void MiddleBoss::Init()
{
	Tag = TAG::ENEMY;

	CircleRadius = 50.f;

	mSprite = IMAGE->AddImage("MiddleBoss", "./image/Enemy/MiddleBoss/MiddleBoss.png");

	HealthInit(550.f);
}

void MiddleBoss::Update()
{
	if (Velocity.x > mSummonPoint.x)
	{
		Math::Lerp(&Velocity, Position, mSummonPoint, 1.5f);

		Position = Velocity;
	}
}

void MiddleBoss::Render()
{
	mSprite->CenterRender(Position, Rotation);
}

void MiddleBoss::Release()
{
}

void MiddleBoss::OnCollisionEnter(Object* other)
{
}

void MiddleBoss::OnCollisionStay(Object* other)
{
}

void MiddleBoss::OnCollisionExit(Object* other)
{
}
