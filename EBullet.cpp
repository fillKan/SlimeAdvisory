#include "DXUT.h"
#include "EBullet.h"

#include "PBulletBreak.h"

EBullet::EBullet(Vector2 pos, Vector2 target, float speed) : mSpeed(speed)
{
	Position  = pos;

	Direction = Math::AimVector(target, pos);
	// 아크 탄젠트는? 탄젠트의 역함수로 세타값을 그 위치로 바꿔주는? 탄젠트 함수와는 반대로 작동한다~~
	// 그렇기 때문에? 방향 벡터를 통해서 그 세타값을 반환받는 방식으로 회전을 정한다~~~
	// 그런데 180도(라디안임)을 더해주는 이유는, DX의 좌표계가 그..일반적인 좌표계랑 다르기 때문에
	// 반전을 시켜준다는 의미로 일허게한다!!
	Rotation = atan2f(Direction.y, Direction.x) + 180 * TO_RADIAN;
}

EBullet::~EBullet()
{
}

void EBullet::Init()
{
	Name = "EBullet";
	Tag = TAG::EBULLET;

	mAnimation.AddFrame("./image/Enemy/Bullet/", "MonsterBullet", 6);

	CircleRadius = 15.f;
}

void EBullet::Update()
{
	Velocity = ZERO;

	Position += (Velocity += mSpeed * Direction);
}

void EBullet::Render()
{
	IMAGE->CenterRender(mAnimation.Play(), Position, Rotation);
}

void EBullet::Release()
{
}

void EBullet::OnCollisionEnter(Object* other)
{
	if (other->Tag == TAG::PLAYER)
	{
		IsDestory = true;

		PARTICLE->Instantiate(PARTICLES::PBULLET_BREAK, Position);
	}
}

void EBullet::OnCollisionStay(Object* other)
{
}

void EBullet::OnCollisionExit(Object* other)
{
}
