#pragma once
class Input : public Singleton<Input>
{
private:
	bool mCurrentInput[256];
	bool    mPrevInput[256];

	bool mCurrentMouse[2];
	bool    mPrevMouse[2];

public:
	void Update();

	bool GetKey    (UINT keyCode);
	bool GetKeyUp  (UINT keyCode);
	bool GetKeyDown(UINT keyCode);

	bool GetMouse    (UINT mouse);
	bool GetMouseUp  (UINT mouse);
	bool GetMouseDown(UINT mouse);
};

#define INPUT Input::Instance()