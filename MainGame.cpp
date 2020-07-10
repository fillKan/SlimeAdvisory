#include "DXUT.h"
#include "MainGame.h"

#include "StageONE.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::Init()
{
	srand(time(NULL));

	SCENCE->AddScence("StageONE", new StageONE());

	SCENCE->LoadScence("StageONE");
}

void MainGame::Update()
{
	CAMERA->Update();
	 INPUT->Update();
	SCENCE->Update();
	OBJECT->Update();

	USER_INTERFACE->Update();
}

void MainGame::Render()
{
	CAMERA->TransformUpdate();

	IMAGE->Begin();

	SCENCE->Render();
	OBJECT->Render();

	USER_INTERFACE->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	 Sound::ReleaseInstance();
	 Input::ReleaseInstance();
	Camera::ReleaseInstance();

	ParticleAdmin::ReleaseInstance();
	UserInterface::ReleaseInstance();
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
