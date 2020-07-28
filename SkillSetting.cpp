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

	Q = IMAGE->AddImage("Q", "./image/UI/Q.png");
	E = IMAGE->AddImage("E", "./image/UI/E.png");

	mHCloudPos[0] = ZERO; mHCloudPos[1] = Vector2(WINSIZEX, 0);
	mMCloudPos[0] = ZERO; mMCloudPos[1] = Vector2(WINSIZEX, 0);
	mSCloudPos[0] = ZERO; mSCloudPos[1] = Vector2(WINSIZEX, 0);

	mBackGround = IMAGE->GetImage("BackGround");

	mExitButton = new Button(Vector2(WINSIZEX * 0.9f, WINSIZEY * 0.9f));
	mExitButton->SetChangeImage("Exit/Exit1", "Exit/Exit2", "Exit/Exit3");
	mExitButton->SetButtonScale(RECT{ -35, -25, 33, 17 });

	USER_INTERFACE->AddUI(mExitButton);

	Button* skillBtn;

	skillBtn = new Button(Vector2(WINSIZEX * 0.35f, WINSIZEY * 0.45f));
	skillBtn->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	skillBtn->SetButtonScale(RECT{ -86, -82, 80, 87 }); // 42 46 208 215 - 이미지ㅡ기으 절반
	skillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);

	mBlankShout = new SkillButton(skillBtn);

	USER_INTERFACE->AddUI(skillBtn);

	skillBtn = new Button(Vector2(WINSIZEX * 0.65f, WINSIZEY * 0.45f));
	skillBtn->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	skillBtn->SetButtonScale(RECT{ -86, -82, 80, 87 }); // 42 46 208 215
	skillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);

	mSteamPack = new SkillButton(skillBtn);

	USER_INTERFACE->AddUI(skillBtn);

	skillBtn = new Button(Vector2(WINSIZEX * 0.5f, WINSIZEY * 0.45f));
	skillBtn->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	skillBtn->SetButtonScale(RECT{ -86, -82, 80, 87 }); // 42 46 208 215
	skillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);

	mGuideMissile = new SkillButton(skillBtn);

	USER_INTERFACE->AddUI(skillBtn);
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
	if (mBlankShout->SkillBtn->OnClick())
	{
		SkillSelect(mBlankShout);
	}
	if (mSteamPack->SkillBtn->OnClick())
	{
		SkillSelect(mSteamPack);
	}
	if (mGuideMissile->SkillBtn->OnClick())
	{
		SkillSelect(mGuideMissile);
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

	Q->CenterRender(Vector2(WINSIZEX * 0.5f, WINSIZEY * 0.45f));
	E->CenterRender(Vector2(WINSIZEX * 0.65f, WINSIZEY * 0.45f));
}

void SkillSetting::Release()
{
	USER_INTERFACE->Release();

	SAFE_DELETE(mBlankShout);
	SAFE_DELETE(mSteamPack);
}

void SkillSetting::SkillSelect(SkillButton* skillButton)
{
	skillButton->mHasSelect = !skillButton->mHasSelect;

	if (skillButton->mHasSelect)
	{
		skillButton->SkillBtn->SetRenderPara(ONE * 2, SELECTCOLOR);
	}
	else
	{
		skillButton->SkillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);
	}
}
