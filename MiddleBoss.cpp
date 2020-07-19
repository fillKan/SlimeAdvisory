#include "DXUT.h"
#include "MiddleBoss.h"

MiddleBoss::MiddleBoss(Vector2 pos, float degree) : Object(), degree(degree)
{
	Position = pos;
}

MiddleBoss::~MiddleBoss()
{
}

void MiddleBoss::Init()
{
	Tag = TAG::ENEMY;

	CircleRadius = 30.f;

	mSprite = IMAGE->AddImage("MiddleBoss", "./image/Enemy/MiddleBoss/MiddleBoss.png");

	HealthInit(300.f);

	Velocity = Vector2(Math::CosGraph(60.f, degree), Math::SinGraph(60.f, degree));

	Position += Velocity * 2.3f;
}

void MiddleBoss::Update()
{
	Velocity = Vector2(Math::CosGraph(180.f, degree), Math::SinGraph(180.f, degree));

	Position += Velocity * DELTA_TIME * 2.3f;

	degree += 2.5f;
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
