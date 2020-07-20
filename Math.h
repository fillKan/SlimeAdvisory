#pragma once
class Object;

namespace Math
{
	inline float Distance(Vector2 pointA, Vector2 pointB)
	{
		return sqrtf(pow(pointA.x - pointB.x, 2) + pow(pointA.y - pointB.y, 2));
	}

	inline Vector2 Lerp(Vector2 start, Vector2 end, float amount)
	{
		return Vector2(((1 - amount) * start.x) + (amount * end.x), ((1 - amount) * start.y) + (amount * end.y));
	}

	inline float Lerp(float start, float end, float amount)
	{
		return ((1 - amount) * start + amount * end);
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

	float DegreeAngle(Vector2 target, Vector2 tracer);

	float RadianAngle(Vector2 target, Vector2 tracer);

	Vector2 RandomCirclePoint(Vector2 pivot);

	Vector2  AimVector(Vector2 target, Vector2 tracer);
};
