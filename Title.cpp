#include "DXUT.h"
#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
}

void Title::Init()
{
	mBackGround = IMAGE->AddImage("BackGround", "./image/BackGround/backgruond.png");

	mTitle = IMAGE->AddImage("MainLogo", "./image/Title/MainLogo.png");

	mHCloud[0] = IMAGE->AddImage("CloudHuge", "./image/BackGround/Cloud/Cloud1.png");
	mHCloud[1] = mHCloud[0];

	mMCloud[0] = IMAGE->AddImage("CloudMiddle", "./image/BackGround/Cloud/Cloud2.png");
	mMCloud[1] = mMCloud[0];

	mSCloud[0] = IMAGE->AddImage("CloudSmall", "./image/BackGround/Cloud/Cloud3.png");
	mSCloud[1] = mSCloud[0];

	mHCloudPos[0] = ZERO; mHCloudPos[1] = Vector2(WINSIZEX, 0);
	mMCloudPos[0] = ZERO; mMCloudPos[1] = Vector2(WINSIZEX, 0);
	mSCloudPos[0] = ZERO; mSCloudPos[1] = Vector2(WINSIZEX, 0);
}

void Title::Update()
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
}

void Title::Render()
{
	mBackGround->Render(ZERO);

	mSCloud[0]->Render(mSCloudPos[0]);
	mSCloud[1]->Render(mSCloudPos[1]);

	mMCloud[0]->Render(mMCloudPos[0]);
	mMCloud[1]->Render(mMCloudPos[1]);

	mHCloud[0]->Render(mHCloudPos[0]);
	mHCloud[1]->Render(mHCloudPos[1]);

	mTitle->CenterRender(WINSIZEX / 2, WINSIZEY * 0.3f);
}

void Title::Release()
{
}