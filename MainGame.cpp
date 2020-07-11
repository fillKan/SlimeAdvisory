#include "DXUT.h"
#include "MainGame.h"

#include "StageONE.h"

#include "PBulletBreak.h"
#include "PAttack.h"

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

	PARTICLE->AddParticle(PARTICLES::PBULLET_BREAK, new PBulletBreak(ZERO));
	PARTICLE->AddParticle(PARTICLES::PATTACK, new PAttack(ZERO));

	SCENCE->LoadScence("StageONE");
}

void MainGame::Update()
{
	CAMERA->Update();
	 INPUT->Update();
	SCENCE->Update();
	OBJECT->Update();

	PARTICLE->Update();

	USER_INTERFACE->Update();
}

void MainGame::Render()
{
	CAMERA->TransformUpdate();

	IMAGE->Begin();

	SCENCE->Render();
	OBJECT->Render();

	PARTICLE->Render();

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
