#include "DXUT.h"
#include "Player.h"

#include "PBullet.h"
#include "DummyEnemy.h"

#include "PBoost.h"
#include "SkillGauge.h"

Player::Player() : mCircleShout(1.3f), mBlank(1.3f), mSteamPack(2.75f, 6.f, 2.f)
{
	mEnergyCube  = nullptr;
	mBoostEffect = nullptr;
}

Player::~Player()
{
	mAnimation.Clear();

	if (mEnergyCube != nullptr)
	{
		mEnergyCube->SetDestroy(true);
	}
}

void Player::Init()
{
#pragma region 플레이어 능력치 설정

	Name = "Player";
	Tag = TAG::PLAYER;

	Position = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	mATKpoint = Position + ATK_POINT_OFFSET;

	mAnimation.SetFrame("./image/Player/Default/", "Player", 18);

	CircleRadius = 50.f;

	mSpeed = 15.f;
	
	HealthInit(10.f);

#pragma endregion

	mATKcool.SetTimer(0.15f, true);

#pragma region 플레이어가 공격할때 나오는 이펙트 객체 설정

	mBoostEffect = new PBoost();
	OBJECT->AddObject(mBoostEffect);

	this->Child = mBoostEffect;
	mBoostEffect->Parent = this;

	mEnergyCube = PARTICLE->Instantiate(PARTICLES::PATTACK, mATKpoint);

#pragma endregion

	SkillGauge* skillGauge;

	skillGauge = new SkillGauge(Vector2(55.f, 210.f));
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
	mATKpoint = Position + ATK_POINT_OFFSET;

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

	if (INPUT->GetKey(ATTACKKEY) && mATKcool.TimeOver())
	{
		Object* target = OBJECT->ForwardCloest(Position, TAG::ENEMY);

		Vector2 dir = RIGHT;
		float   rot = 0.00f;

		if (target != nullptr)
		{
			dir = Math::AimVector(target->Position, mATKpoint);

			rot = Math::RadianAngle(mATKpoint, target->Position);
		}
		OBJECT->AddObject(new PBullet(mATKpoint, dir, rot));
	}

	Vector2 velocity = ZERO;

	velocity += (UP    * mSpeed * INPUT->GetKey('W')) + (DOWN * mSpeed * INPUT->GetKey('S')) +
				(RIGHT * mSpeed * INPUT->GetKey('D')) + (LEFT * mSpeed * INPUT->GetKey('A')) + Position;

	if (velocity.x > 0 && velocity.x < WINSIZEX) { Position.x = velocity.x; }
	if (velocity.y > 0 && velocity.y < WINSIZEY) { Position.y = velocity.y; }


	mBoostEffect->Position = Position + BOOST_OFFSET;
	 mEnergyCube->Position = mATKpoint;
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
