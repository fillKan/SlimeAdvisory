#include "DXUT.h"
#include "Player.h"

#include "PBullet.h"
#include "DummyEnemy.h"

#include "PBoost.h"
#include "SkillGauge.h"

Player::Player() : mCircleShout(0.8f), mBlank(0.8f), mSteamPack(3.5f, 5.f, 2.25f)
{
	mAttackParticle = nullptr;
	mBoostEffect    = nullptr;
}

Player::~Player()
{
	mAnimation.Clear();

	if (mAttackParticle != nullptr)
	{
		mAttackParticle->SetDestroy(true);
	}
}

void Player::Init()
{
	Name = "Player";
	Tag = TAG::PLAYER;

	Position = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	mAttackPoint = (Position + Vector2(130.5f, 20.5f));

	mAnimation.SetFrame("./image/Player/Default/", "Player", 18);

	CircleRadius = 50.f;

	mSpeed = 12.f;

	mATKcool.SetTimer(0.15f, true);

	mAttackParticle = nullptr;

	mBoostEffect = new PBoost();
	OBJECT->AddObject(mBoostEffect);

	this->Child = mBoostEffect;
	mBoostEffect->Parent = this;

	HealthInit(10.f);

	SkillGauge* skillGauge = new SkillGauge(Vector2(55.f, 210.f));
	skillGauge->SkillLink(&mBlank);
	skillGauge->SetImage(IMAGE->AddImage("ESkillGauge", "./image/UI/SkillGaugeBlank.png"), 
						 IMAGE->AddImage("SkillGauge", "./image/UI/SSkillGauge.png"));

	USER_INTERFACE->AddUI(skillGauge);

	skillGauge = new SkillGauge(Vector2(125.f, 210.f));
	skillGauge->SkillLink(&mSteamPack);
	skillGauge->SetImage(IMAGE->GetImage("ESkillGauge"),
						 IMAGE->GetImage("SkillGauge"));

	USER_INTERFACE->AddUI(skillGauge);
}

void Player::Update()
{
	if (CURHealth <= 0)
	{
		SCENCE->LoadScence("Title");
	}

	mATKcool.Update();
	mCircleShout.Update();
	mBlank.Update();
	mSteamPack.Update();

	if (INPUT->GetKeyDown('Q'))
	{
		mCircleShout.CastSkill();
		mBlank.CastSkill();
	}
	if (INPUT->GetKeyDown('E'))
	{
		mSteamPack.CastSkill();
	}

	if (INPUT->GetKeyDown(ATTACKKEY) && mAttackParticle == nullptr)
	{
		mAttackParticle = PARTICLE->Instantiate(PARTICLES::PATTACK, mAttackPoint);
	}
	if (INPUT->GetKey(ATTACKKEY) && mATKcool.TimeOver())
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
	Vector2 velocity = ZERO;

	if (GetAsyncKeyState('W'))
	{
		if (Position.y > 0) velocity += UP * mSpeed;
	}
	else if (GetAsyncKeyState('S'))
	{
		if (Position.y < WINSIZEY) velocity += DOWN * mSpeed;
	}
	if (GetAsyncKeyState('D'))
	{
		if (Position.x < WINSIZEX) velocity += RIGHT * mSpeed;
	}
	else if (GetAsyncKeyState('A'))
	{
		if (Position.x > 0) velocity += LEFT * mSpeed;
	}
	Position += velocity;

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
}

void Player::OnCollisionStay(Object* other)
{
}

void Player::OnCollisionExit(Object* other)
{
}
