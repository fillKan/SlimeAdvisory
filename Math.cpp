#include "DXUT.h"
#include "Math.h"

float Math::DegreeAngle(Vector2 pointA, Vector2 pointB)
{
	float degree = TO_DEGREE * atan2f((pointA.x - pointB.x), (pointA.y - pointB.y)) - GRAPH_CORRECTION;

	return (degree < 0.f) ? -degree : degree;
}

float Math::RadianAngle(Vector2 pointA, Vector2 pointB)
{
	float radian = atan2f((pointA.x - pointB.x), (pointA.y - pointB.y)) - GRAPH_CORRECTION;

	return (radian < 0.f) ? -radian : radian;
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
