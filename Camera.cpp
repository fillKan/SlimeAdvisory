#include "DXUT.h"
#include "Camera.h"

void Camera::Update()
{
	float deltaTime = DELTA_TIME;

	if (mTraceObject != nullptr && mIsTrace)
	{
		mCanMove = (Math::Distance(mPosition, mTraceObject->Position) >= 1);

		if (mCanMove)
		{
			mPosition = Math::Lerp(mPosition, mTraceObject->Position, 2.f);
			mScale	  = Math::Lerp(mScale, mMaxScale, 2.f);
		}
	}

	if (mShakeTime > 0)
	{
		mShakeTime -= deltaTime;

		mPosition += Vector2(RANDOM(-1, 1) + RANDOM(-10, 10) * 0.1f, RANDOM(-1, 1) + RANDOM(-10, 10) * 0.1f);
	}
	else if (mIsTrace) mPosition = mBasicPos;

	mVlewMat = Matrix
	(
		 mScale.x * cos(mRotation), mScale.y * sin(mRotation), 0.f, 0.f,
		-mScale.y * sin(mRotation), mScale.y * cos(mRotation), 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		-mPosition.x * mScale.x * cos(mRotation) + mScale.y				  * sin(mRotation),
		-mPosition.x * mScale.y * sin(mRotation) - mScale.y * mPosition.y * cos(mRotation), 0.f, 1.f
	);
}

void Camera::TransformUpdate()
{
	DEVICE->SetTransform(D3DTS_VIEW, &mVlewMat);
	DEVICE->SetTransform(D3DTS_PROJECTION, &mProjectionMat);
}

void Camera::Shake(float durate)
{
	if (mShakeTime <= durate + ELAPSED)
	{
		mShakeTime  = durate + ELAPSED;
	}
}

Camera::Camera()
{
	Init();
}

Camera::~Camera()
{
	Release();
}

void Camera::Init()
{
	mPosition = mBasicPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	mRotation = 0.f;

	mScale    = ONE;
	mMaxScale = ONE;
	mVlewSize = Vector2((float)WINSIZEX, (float)WINSIZEY);

	D3DXMatrixOrthoLH(&mProjectionMat, mVlewSize.x, -mVlewSize.y, 0, 1);

	mTraceObject = nullptr;
	mIsTrace = false;

	mCanMove = false;
	mShakeTime = 0.f;
}

void Camera::Release()
{
	SAFE_DELETE(mTraceObject);
}
