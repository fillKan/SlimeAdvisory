#include "DXUT.h"
#include "Math.h"

float Math::DegreeAngle(Vector2 target, Vector2 tracer)
{
	return RadianAngle(target, tracer) * TO_DEGREE;
}

float Math::RadianAngle(Vector2 target, Vector2 tracer)
{
	Vector2 Aim = target - tracer;

	// 아크 탄젠트는? 탄젠트의 역함수로 세타값을 그 위치로 바꿔주는? 탄젠트 함수와는 반대로 작동한다~~
	// 그렇기 때문에? 방향 벡터를 통해서 그 세타값을 반환받는 방식으로 회전을 정한다~~~
	// 그런데 180도(라디안임)을 더해주는 이유는, DX의 좌표계가 그..일반적인 좌표계랑 다르기 때문에
	// 반전을 시켜준다는 의미로 일허게한다!!

	return atan2f(Aim.y, Aim.x) + PI;
}

bool Math::RectCollision(Object* objectA, Object* objectB)
{
	/*Vector2 ALeftTop   = objectA->collider.leftTop   + objectA->Position;
	Vector2 ARightDown = objectA->collider.rightDown + objectA->Position;

	Vector2 BLeftTop   = objectB->collider.leftTop   + objectB->Position;
	Vector2 BRightDown = objectB->collider.rightDown + objectB->Position;

	return (ALeftTop.x < BRightDown.x &&
			ALeftTop.y < BRightDown.y &&
			BLeftTop.x < ARightDown.x &&
			BLeftTop.y < ARightDown.y);*/

	return false;
}

Vector2 Math::RandomCirclePoint(Vector2 pivot)
{
	float degree = rand() / (float)RAND_MAX * 360.f;

	return Vector2(cos(degree), sin(degree));
}

Vector2 Math::AimVector(Vector2 target, Vector2 tracer)
{
	Vector2 Aim = target - tracer;

	return Aim / Distance(target, tracer);
}

Vector2* Math::RadiateVector(Vector2 point, float theta, int num)
{
	return nullptr;
}

Vector2 Math::ThetaVector(float theta)
{
	return Vector2();
}

Vector2 Math::Accelerate(Vector2 velocity, float accel, float speed)
{
	return Vector2();
}

Vector2 Math::BezierCurve(Vector2 lBot, Vector2 lTop, Vector2 rBot, Vector2 rTop, float& time, float speed, bool reverse)
{
	return Vector2();
}
