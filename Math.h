#pragma once
#include "Object.h"

namespace Math
{
	inline float Distance(Vector2 pointA, Vector2 pointB)
	{
		return sqrtf(pow(pointA.x - pointB.x, 2) + pow(pointA.y - pointB.y, 2));
	}

	inline Vector2 Lerp(Vector2 start, Vector2 end, float value)
	{
		return start + (end - start) * value * DELTA_TIME;
	}

	inline float SinGraph(float radius, float degree, float offset = 0.f)
	{
		return (sin(degree * TO_RADIAN) * radius) + offset;
	}

	inline float CosGraph(float radius, float degree, float offset = 0.f)
	{
		return (cos(degree * TO_RADIAN) * radius) + offset;
	}

	inline bool CircleCollision(Vector2 pointA, float radiusA, Vector2 pointB, float radiusB)
	{
		return (Math::Distance(pointA, pointB) <= radiusA + radiusB);
	}

	float DegreeAngle(Vector2 pointA, Vector2 pointB)
	{
		float degree = TO_DEGREE * atan2f((pointA.x - pointB.x), (pointA.y - pointB.y)) - GRAPH_CORRECTION;

		return (degree < 0.f) ? -degree : degree;
	}

	bool RectCollision(Object* objectA, Object* objectB)
	{
		Vector2 ALeftTop   = objectA->collider.leftTop   + objectA->Position;
		Vector2 ARightDown = objectA->collider.rightDown + objectA->Position;
		
		Vector2 BLeftTop   = objectB->collider.leftTop   + objectB->Position;
		Vector2 BRightDown = objectB->collider.rightDown + objectB->Position;

		return (ALeftTop.x < BRightDown.x && 
				ALeftTop.y < BRightDown.y &&
				BLeftTop.x < ARightDown.x && 
				BLeftTop.y < ARightDown.y);
	}

	float RadianAngle(Vector2 pointA, Vector2 pointB)
	{
		float radian = atan2f((pointA.x - pointB.x), (pointA.y - pointB.y)) - GRAPH_CORRECTION;

		return (radian < 0.f) ? -radian : radian;
	}

	Vector2  AimVector(Vector2 target, Vector2 tracer);

	Vector2* RadiateVector(Vector2 point, float theta, int num);

	Vector2  ThetaVector(float theta);

	Vector2  Accelerate(Vector2 velocity, float accel, float speed);

	Vector2  BezierCurve(Vector2 lBot, Vector2 lTop, Vector2 rBot, Vector2 rTop, float& time, float speed, bool reverse);
};
