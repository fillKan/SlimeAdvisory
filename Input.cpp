#include "DXUT.h"
#include "Input.h"

Input::Input() : mHandle(FindWindow(NULL, TITLE))
{
}

Input::~Input()
{
}

void Input::Update()
{
	for (int i = 0; i < 256; ++i)
	{
		mPrevInput[i] = mCurrentInput[i];

		if (GetAsyncKeyState(i))
		{
			 mCurrentInput[i] =  true;
		}
		else mCurrentInput[i] = false;
	}

	mPrevInput[0] = mCurrentInput[0];
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		 mCurrentInput[0] =  true;
	}
	else mCurrentInput[0] = false;

	mPrevInput[1] = mCurrentInput[1];
	if (GetAsyncKeyState(VK_RBUTTON))
	{
		 mCurrentInput[1] =  true;
	}
	else mCurrentInput[1] = false;
}

bool Input::GetKey(UINT keyCode)
{
	return mCurrentInput[keyCode] && mPrevInput[keyCode];
}

bool Input::GetKeyUp(UINT keyCode)
{
	return !mCurrentInput[keyCode] && mPrevInput[keyCode];
}

bool Input::GetKeyDown(UINT keyCode)
{
	return mCurrentInput[keyCode] && !mPrevInput[keyCode];
}

bool Input::GetMouse(UINT mouse)
{
	return mCurrentMouse[mouse] && mPrevMouse[mouse];
}

bool Input::GetMouseUp(UINT mouse)
{
	return !mCurrentMouse[mouse] && mPrevMouse[mouse];
}

bool Input::GetMouseDown(UINT mouse)
{
	return mCurrentMouse[mouse] && !mPrevMouse[mouse];
}

Vector2 Input::CursorPos()
{
	tagPOINT point;

	GetCursorPos(&point);

	ScreenToClient(mHandle, &point);

	return Vector2(point.x, point.y);
}