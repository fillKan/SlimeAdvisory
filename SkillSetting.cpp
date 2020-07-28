#include "DXUT.h"
#include "SkillSetting.h"

SkillSetting::SkillSetting()
{
}

SkillSetting::~SkillSetting()
{
}

void SkillSetting::Init()
{
	mHCloud[0] = IMAGE->GetImage("CloudHuge");
	mHCloud[1] = mHCloud[0];

	mMCloud[0] = IMAGE->GetImage("CloudMiddle");
	mMCloud[1] = mMCloud[0];

	mSCloud[0] = IMAGE->GetImage("CloudSmall");
	mSCloud[1] = mSCloud[0];

	mHCloudPos[0] = ZERO; mHCloudPos[1] = Vector2(WINSIZEX, 0);
	mMCloudPos[0] = ZERO; mMCloudPos[1] = Vector2(WINSIZEX, 0);
	mSCloudPos[0] = ZERO; mSCloudPos[1] = Vector2(WINSIZEX, 0);

	mBackGround = IMAGE->GetImage("BackGround");

	mExitButton = new Button(Vector2(WINSIZEX * 0.9f, WINSIZEY * 0.9f));
	mExitButton->SetChangeImage("Exit/Exit1", "Exit/Exit2", "Exit/Exit3");
	mExitButton->SetButtonScale(RECT{ -35, -25, 33, 17 });

	USER_INTERFACE->AddUI(mExitButton);
}

void SkillSetting::Update()
{
	for (int i = 0; i < 2; ++i)
	{
		mHCloudPos[i] += LEFT * HUGE_CLOUD_SPEED;
		mMCloudPos[i] += LEFT * MIDDLE_CLOUD_SPEED;
		mSCloudPos[i] += LEFT * SMALL_CLOUD_SPEED;

		if (mHCloudPos[i].x <= -WINSIZEX) { mHCloudPos[i].x = WINSIZEX; }
		if (mMCloudPos[i].x <= -WINSIZEX) { mMCloudPos[i].x = WINSIZEX; }
		if (mSCloudPos[i].x <= -WINSIZEX) { mSCloudPos[i].x = WINSIZEX; }
	}
	if (mExitButton->OnClick())
	{
		SCENCE->LoadScence("Title");
	}
}

void SkillSetting::Render()
{
	mBackGround->Render(ZERO);

	mSCloud[0]->Render(mSCloudPos[0]);
	mSCloud[1]->Render(mSCloudPos[1]);

	mMCloud[0]->Render(mMCloudPos[0]);
	mMCloud[1]->Render(mMCloudPos[1]);

	mHCloud[0]->Render(mHCloudPos[0]);
	mHCloud[1]->Render(mHCloudPos[1]);
}

void SkillSetting::Release()
{
	USER_INTERFACE->Release();
}
