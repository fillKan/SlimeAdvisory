#include "DXUT.h"
#include "Player.h"

#include "PBullet.h"
#include "DummyEnemy.h"

#include "PBoost.h"
#include "SkillGauge.h"

Player::Player() : mCircleShout(0.8f), mBlank(0.8f)
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

	CircleRadius = 50.f;

	mSpeed = 12.f;

	mTimer.SetTimer(0.15f, true);

	mAttackParticle = nullptr;

	mBoostEffect = new PBoost();
	OBJECT->AddObject(mBoostEffect);

	this->Child = mBoostEffect;
	mBoostEffect->Parent = this;

	HealthInit(10.f);

	SkillGauge* skillGauge = new SkillGauge(Vector2(420.f, 120.f));
	skillGauge->SkillLink(&mBlank);
	skillGauge->SetImage(IMAGE->AddImage("ESkillGauge", "./image/UI/ESkillGauge.png"), 
						 IMAGE->AddImage("SkillGauge", "./image/UI/SkillGauge.png"));

	USER_INTERFACE->AddUI(skillGauge);
}

void Player::Update()
{
	Velocity = ZERO;

	mTimer.Update();
	mCircleShout.Update();
	mBlank.Update();

	if (INPUT->GetKeyDown('Q'))
	{
		mCircleShout.CastSkill();
		mBlank.CastSkill();
	}

	if (INPUT->GetKeyDown(ATTACKKEY) && mAttackParticle == nullptr)
	{
		mAttackParticle = PARTICLE->Instantiate(PARTICLES::PATTACK, mAttackPoint);
	}
	if (INPUT->GetKey(ATTACKKEY) && mTimer.TimeOver())
	{
		Object* cloestObj = OBJECT->ForwardCloest(Position, TAG::ENEMY);

		Vector2 dir = RIGHT;
		float rot = 0.f;

		if (cloestObj != nullptr)
		{
			dir = Math::AimVector(cloestObj->Position, mAttackPoint);

			rot = Math::RadianAngle(mAttackPoint, cloestObj->Position);
		}
		OBJECT->AddObject(new PBullet(mAttackPoint, dir, rot));
	}
	if (GetAsyncKeyState('W'))
	{
		if (Position.y > 0) Velocity += UP * mSpeed;
	}
	else if (GetAsyncKeyState('S'))
	{
		if (Position.y < WINSIZEY) Velocity += DOWN * mSpeed;
	}
	if (GetAsyncKeyState('D'))
	{
		if (Position.x < WINSIZEX) Velocity += RIGHT * mSpeed;
	}
	else if (GetAsyncKeyState('A'))
	{
		if (Position.x > 0) Velocity += LEFT * mSpeed;
	}
	Position += Velocity;

	mAttackPoint = (Position + ATK_PARTICLE_OFFSET);

	mBoostEffect->Position = (Position + BOOST_OFFSET);

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
	if (CURHealth <= 0)
	{
		CURHealth = MAXHealth;
	}
}

void Player::OnCollisionStay(Object* other)
{
}

void Player::OnCollisionExit(Object* other)
{
}
