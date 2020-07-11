#include "DXUT.h"
#include "StageONE.h"

#include "Player.h"
#include "DummyEnemy.h"

void StageONE::Init()
{
	mButton = new Button(Vector2(WINSIZEX - 160, 20));
	mButton->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	mButton->SetButtonScale(RECT{ 0, 0, 128, 128 });

	mBackGround = IMAGE->AddImage("BackGround","./image/BackGround/backgruond.png");

	mEnemySpawnTimer.SetTimer(0.2f, true);

	OBJECT->AddObject(new Player());

	USER_INTERFACE->AddUI(new PHealthBar());
	USER_INTERFACE->AddUI(mButton);

	mCloudHuge[0] = IMAGE->AddImage("CloudHuge", "./image/BackGround/Cloud/Cloud1.png");
	mCloudHuge[1] = mCloudHuge[0];

	mCloudMiddle[0] = IMAGE->AddImage("CloudMiddle", "./image/BackGround/Cloud/Cloud2.png");
	mCloudMiddle[1] = mCloudMiddle[0];

	mCloudSmall[0] = IMAGE->AddImage("CloudSmall", "./image/BackGround/Cloud/Cloud3.png");
	mCloudSmall[1] = mCloudSmall[0];
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
	mBackGround->Render(ZERO);

	mCloudHuge[0]->Render(ZERO);
	//mCloudHuge[1]->Render(ZERO);

	mCloudMiddle[0]->Render(ZERO);
	//mCloudMiddle[1]->Render(ZERO);

	mCloudSmall[0]->Render(ZERO);
	//mCloudSmall[1]->Render(ZERO);
}

void StageONE::Release()
{
	USER_INTERFACE->Release();
}
