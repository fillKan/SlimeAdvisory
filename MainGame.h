#pragma once
class MainGame
{
public:
	 MainGame();
	~MainGame();

	void Init   ();
	void Update ();
	void Render ();
	void Release();

	void  LostDevice();
	void ResetDevice();

private:

	Timer mTimer;
};

