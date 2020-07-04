#include "DXUT.h"
#include "Math.h"

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

Vector2 Math::AimVector(Vector2 target, Vector2 tracer)
{
	return Vector2();
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
