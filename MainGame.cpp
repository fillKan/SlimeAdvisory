#include "DXUT.h"
#include "MainGame.h"

#include "DummyEnemy.h"
#include "Player.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::Init()
{
	srand(time(NULL));
	OBJECT->AddObject(new Player());

	OBJECT->AddObject(new DummyEnemy());

	mTimer.SetTimer(0.35f, true);
}

void MainGame::Update()
{
	if (mTimer.TimeOver())
	{
		OBJECT->AddObject(new DummyEnemy());
	}
	CAMERA->Update();
	 INPUT->Update();
	SCENCE->Update();
	OBJECT->Update();
}

void MainGame::Render()
{
	CAMERA->TransformUpdate();

	IMAGE->Begin();

	SCENCE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	 Sound::ReleaseInstance();
	 Input::ReleaseInstance();
	Camera::ReleaseInstance();

	 ImageManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	ScenceManager::ReleaseInstance();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}
