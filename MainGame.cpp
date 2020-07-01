#include "DXUT.h"
#include "MainGame.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::Init()
{
}

void MainGame::Update()
{
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
