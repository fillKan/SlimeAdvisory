#pragma once

#include "Object.h"

class Camera : public Singleton<Camera>
{
private:
	Matrix mProjectionMat, mVlewMat;
	Vector2 mVlewSize;

public:
	Vector2 mBasicPos;
	Vector2 mPosition;

	float   mRotation;

	Vector2 mMaxScale;
	Vector2 mScale;

	Object* mTraceObject;
	bool    mIsTrace;
	bool	mCanMove;

	float mShakeTime;

public:
	void Update();
	void TransformUpdate();

	void Shake(float durate);

	 Camera();
	~Camera();

private:
	void Init  ();
	void Release();
};
#define CAMERA Camera::Instance()
