#include "DXUT.h"
#include "SkillSetting.h"

SkillSetting::SkillSetting() : Q(IMAGE->AddImage("Q", "./image/UI/Q.png"), ZERO), E(IMAGE->AddImage("E", "./image/UI/E.png"), ZERO)
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

	mBlankShoutText = IMAGE->AddImage("BlankShoutText", "./image/UI/Text/BlankShoutText.png");
	mSteamPackText = IMAGE->AddImage("SteamPackText", "./image/UI/Text/SteamPackText.png");
	mGuideMissileText = IMAGE->AddImage("GuideMissileText", "./image/UI/Text/GuideMissileText.png");

	mHCloudPos[0] = ZERO; mHCloudPos[1] = Vector2(WINSIZEX, 0);
	mMCloudPos[0] = ZERO; mMCloudPos[1] = Vector2(WINSIZEX, 0);
	mSCloudPos[0] = ZERO; mSCloudPos[1] = Vector2(WINSIZEX, 0);

	mBackGround = IMAGE->GetImage("BackGround");

	mExitButton = new Button(Vector2(WINSIZEX * 0.9f, WINSIZEY * 0.9f));
	mExitButton->SetChangeImage("Exit/Exit1", "Exit/Exit2", "Exit/Exit3");
	mExitButton->SetButtonScale(RECT{ -35, -25, 33, 17 });

	USER_INTERFACE->AddUI(mExitButton);

	Button* skillBtn;

	skillBtn = new Button(LEFT_SIDE);
	skillBtn->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	skillBtn->SetButtonScale(RECT{ -86, -82, 80, 87 }); // 42 46 208 215 - 이미지ㅡ기으 절반
	skillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);

	mBlankShout = new SkillButton(skillBtn);

	USER_INTERFACE->AddUI(skillBtn);

	skillBtn = new Button(MIDDLE);
	skillBtn->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	skillBtn->SetButtonScale(RECT{ -86, -82, 80, 87 }); // 42 46 208 215
	skillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);

	mSteamPack = new SkillButton(skillBtn);

	USER_INTERFACE->AddUI(skillBtn);

	skillBtn = new Button(RIGHT_SIDE);
	skillBtn->SetChangeImage("DaengDaengYi1", "DaengDaengYi3", "DaengDaengYi2");
	skillBtn->SetButtonScale(RECT{ -86, -82, 80, 87 }); // 42 46 208 215
	skillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);

	mGuideMissile = new SkillButton(skillBtn);

	USER_INTERFACE->AddUI(skillBtn);

	  mBlankShout->LinkSkill = PLAYERSKILL->GetSkill(SKILLS::BLANKSHOUT);
	   mSteamPack->LinkSkill = PLAYERSKILL->GetSkill(SKILLS::STEAMPACK);
	mGuideMissile->LinkSkill = PLAYERSKILL->GetSkill(SKILLS::GUIDEMISSILE);

	  mBlankShout->AttachKey = PLAYERSKILL->GetSkillAttachKey(mBlankShout->LinkSkill);
	   mSteamPack->AttachKey = PLAYERSKILL->GetSkillAttachKey(mSteamPack->LinkSkill);
	mGuideMissile->AttachKey = PLAYERSKILL->GetSkillAttachKey(mGuideMissile->LinkSkill);

	if (mBlankShout->AttachKey == 'Q' || mBlankShout->AttachKey == 'E')
	{
		if (mBlankShout->AttachKey == 'Q')
		{
			Q.Position = mBlankShout->SkillBtn->GPosition();
		}
		else if (mBlankShout->AttachKey == 'E')
		{
			E.Position = mBlankShout->SkillBtn->GPosition();
		}
		mBlankShout->mHasSelect = true;

		mBlankShout->SkillBtn->SetRenderPara(ONE * 2, SELECTCOLOR);
	}
	
	if (mSteamPack->AttachKey == 'Q' || mSteamPack->AttachKey == 'E')
	{
		if (mSteamPack->AttachKey == 'Q')
		{
			Q.Position = mSteamPack->SkillBtn->GPosition();
		}
		else if (mSteamPack->AttachKey == 'E')
		{
			E.Position = mSteamPack->SkillBtn->GPosition();
		}
		mSteamPack->SkillBtn->SetRenderPara(ONE * 2, SELECTCOLOR);

		mSteamPack->mHasSelect = true;
	}
	
	if (mGuideMissile->AttachKey == 'Q' || mGuideMissile->AttachKey == 'E')
	{
		if (mGuideMissile->AttachKey == 'Q')
		{
			Q.Position = mGuideMissile->SkillBtn->GPosition();
		}
		else if (mGuideMissile->AttachKey == 'E')
		{
			E.Position = mGuideMissile->SkillBtn->GPosition();
		}
		mGuideMissile->SkillBtn->SetRenderPara(ONE * 2, SELECTCOLOR);

		mGuideMissile->mHasSelect = true;
	}
	
	Q.HasLinkSkill = (PLAYERSKILL->GetKeyAttachSkill('Q') != nullptr);
	E.HasLinkSkill = (PLAYERSKILL->GetKeyAttachSkill('E') != nullptr);
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

	if (Q.HasLinkSkill)
	{
		Q.Image->CenterRender(Q.Position);
	}
	if (E.HasLinkSkill)
	{
		E.Image->CenterRender(E.Position);
	}

	if (mBlankShout->SkillBtn->OnMouse())
	{
		mBlankShoutText->CenterRender(MIDDLE + DOWN * 250);
	}
	else if (mSteamPack->SkillBtn->OnMouse())
	{
		mSteamPackText->CenterRender(MIDDLE + DOWN * 250);
	}
	else if (mGuideMissile->SkillBtn->OnMouse())
	{
		mGuideMissileText->CenterRender(MIDDLE + DOWN * 250);
	}
}

void SkillSetting::Release()
{
	USER_INTERFACE->Release();

	SAFE_DELETE(mBlankShout);
	SAFE_DELETE(mSteamPack);
	SAFE_DELETE(mGuideMissile);
}

void SkillSetting::SkillSelect(SkillButton* skillButton)
{
	if (skillButton->mHasSelect)
	{
		skillButton->SkillBtn->SetRenderPara(ONE * 2, UN_SELECTCOLOR);

		skillButton->mHasSelect = false;

		if (skillButton->AttachKey == 'Q')
		{
			Q.HasLinkSkill = false;
		}
		else if (skillButton->AttachKey == 'E')
		{
			E.HasLinkSkill = false;
		}
	}

	else
	{
		if (!Q.HasLinkSkill || !E.HasLinkSkill)
		{
			if (!Q.HasLinkSkill)
			{
				Q.HasLinkSkill = true;

				Q.Position = skillButton->SkillBtn->GPosition();

				PLAYERSKILL->SetKeyAttachSkill('Q', skillButton->LinkSkill);

				skillButton->AttachKey = 'Q';
			}
			else if (!E.HasLinkSkill)
			{
				E.HasLinkSkill = true;

				E.Position = skillButton->SkillBtn->GPosition();

				PLAYERSKILL->SetKeyAttachSkill('E', skillButton->LinkSkill);

				skillButton->AttachKey = 'E';
			}
			skillButton->SkillBtn->SetRenderPara(ONE * 2, SELECTCOLOR);

			skillButton->mHasSelect = true;
		}
	}
}
