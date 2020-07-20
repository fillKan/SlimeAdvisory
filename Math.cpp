#include "DXUT.h"
#include "Math.h"

float Math::DegreeAngle(Vector2 target, Vector2 tracer)
{
	return RadianAngle(target, tracer) * TO_DEGREE;
}

float Math::RadianAngle(Vector2 target, Vector2 tracer)
{
	Vector2 Aim = target - tracer;

	return atan2f(Aim.y, Aim.x) + PI;
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