#include "DXUT.h"
#include "Scence.h"

ScenceManager::ScenceManager() : mCurrentScence(nullptr), mNextScence(nullptr)
{
}

ScenceManager::~ScenceManager()
{
	Release();
}

void ScenceManager::AddScence(const string& key, Scence* scence)
{
	auto find = mScences.find(key);

	if (find == mScences.end())
	{
		mScences.insert(make_pair(key, scence));
	}
}

void ScenceManager::LoadScence(const string& key)
{
	auto find = mScences.find(key);

	if (find != mScences.end())
	{
		mNextScence = find->second;
	}
}

void ScenceManager::Update()
{
	if (mNextScence)
	{
		if (mCurrentScence)
		{
			mCurrentScence->Release();
		}
		mCurrentScence = mNextScence;

		mCurrentScence->Init();
		mNextScence = nullptr;
	}
	if (mCurrentScence)
	{
		mCurrentScence->Update();
	}
}

void ScenceManager::Render()
{
	if (mCurrentScence)
	{
		mCurrentScence->Render();
	}
}

void ScenceManager::Release()
{
	if (mCurrentScence)
	{
		mCurrentScence->Release();
	}
	for (auto iter : mScences)
	{
		SAFE_DELETE(iter.second);
	}
	mScences.clear();
}
