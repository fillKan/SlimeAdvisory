#pragma once
class Object;

namespace Math
{
	inline float Distance(Vector2 pointA, Vector2 pointB)
	{
		return sqrtf(pow(pointA.x - pointB.x, 2) + pow(pointA.y - pointB.y, 2));
	}

	inline void Lerp(Vector2* target, Vector2& start, Vector2& end, float value)
	{
		*target = start + (end - start) * value * DELTA_TIME;
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

	bool RectCollision(Object* objectA, Object* objectB);


	Vector2 RandomCirclePoint(Vector2 pivot);

	Vector2  AimVector(Vector2 target, Vector2 tracer);

	Vector2* RadiateVector(Vector2 point, float theta, int num);

	Vector2  ThetaVector(float theta);

	Vector2  Accelerate(Vector2 velocity, float accel, float speed);

	Vector2  BezierCurve(Vector2 lBot, Vector2 lTop, Vector2 rBot, Vector2 rTop, float& time, float speed, bool reverse);
};
