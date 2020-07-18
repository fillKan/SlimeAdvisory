#include "DXUT.h"
#include "SkillGauge.h"

SkillGauge::SkillGauge(Vector2 pos) : mPosition(pos), mLinkSkill(nullptr), UI(UI_RENDER_TYPE::DECREASEBOX_UP)
{
}

SkillGauge::~SkillGauge()
{
}

void SkillGauge::Init()
{
	mImage.RenderType = mRenderType;
}

void SkillGauge::Update()
{
	if (mLinkSkill)
	{
		mImage.SetRect(mRenderType, mLinkSkill->GProgress());
	}
}

void SkillGauge::Render()
{
	mImage.Render(mPosition);
}

void SkillGauge::Release()
{
}

void SkillGauge::SkillLink(Skill* link)
{
	mLinkSkill = link;
}

void SkillGauge::SetImage(Texture* backImage, Texture* fillImage)
{
	mImage.BackImage = backImage;
	mImage.FillImage = fillImage;
}
