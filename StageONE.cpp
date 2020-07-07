#include "DXUT.h"
#include "StageONE.h"

#include "Player.h"
#include "DummyEnemy.h"

void StageONE::Init()
{
	mButton = new Button(Vector2(800, 20));
	mButton->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	mButton->SetButtonScale(RECT{ 0, 0, 128, 128 });

	mEnemySpawnTimer.SetTimer(0.5f, true);

	OBJECT->AddObject(new Player());

	USER_INTERFACE->AddUI(new PHealthBar());
	USER_INTERFACE->AddUI(mButton);
}

void StageONE::Update()
{
	if (mEnemySpawnTimer.TimeOver())
	{
		OBJECT->AddObject(new DummyEnemy());
	}
}

void StageONE::Render()
{
}

void StageONE::Release()
{
	USER_INTERFACE->Release();
}
