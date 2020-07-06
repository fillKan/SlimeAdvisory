#include "DXUT.h"
#include "StageONE.h"

#include "Player.h"
#include "DummyEnemy.h"

void StageONE::Init()
{
	mEnemySpawnTimer.SetTimer(0.5f, true);

	OBJECT->AddObject(new Player());

	mPlayerHPUI.Init();
}

void StageONE::Update()
{
	if (mEnemySpawnTimer.TimeOver())
	{
		OBJECT->AddObject(new DummyEnemy());
	}
	mPlayerHPUI.Update();
}

void StageONE::Render()
{
	mPlayerHPUI.Render();
}

void StageONE::Release()
{
}
