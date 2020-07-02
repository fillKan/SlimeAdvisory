#include "DXUT.h"
#include "Object.h"

Object::Object() : Parent(nullptr), Name(""), Tag(TAG::NONE), IsDestory(false), IsActive(true), IsPrevCollision(false), IsCrntCollision(false), Rotation(0.0f), Position(ZERO), Scale(ONE), ImageSize(ZERO), Velocity(ZERO), CircleRadius(0.f)
{
}

Object::~Object()
{
}

ObjectManager::~ObjectManager()
{
	for (auto iter : mNewObjects)
	{
		SAFE_DELETE(iter);
	}
	mNewObjects.clear();

	for (auto iter : mCurObjects)
	{
		iter->Release();

		SAFE_DELETE(iter);
	}
	mCurObjects.clear();
}

void ObjectManager::AddObject(Object* object)
{
	object->Init();

	mNewObjects.emplace_back(object);
}

Object* ObjectManager::FindObject(const string& name)
{
	for (auto iter : mCurObjects)
	{
		if (iter->Name == name) return iter;
	}
	return nullptr;
}

Object* ObjectManager::FindObject(TAG tag)
{
	for (auto iter : mCurObjects)
	{
		if (iter->Tag == tag) return iter;
	}
	return nullptr;
}

void ObjectManager::CollisionCheck(TAG tagA, TAG tagB)
{
	if (mCurObjects.empty()) return;

	for (auto& iterA = mCurObjects.begin(); iterA != mCurObjects.end(); iterA++)
	{
		if ((*iterA)->Tag != tagA) continue;

		for (auto& iterB = mCurObjects.begin(); iterB != mCurObjects.end(); iterB++)
		{
			if ((*iterB)->Tag != tagB) continue;

			if (Math::Distance((*iterA)->Position, (*iterB)->Position) <= 50.f)
			{
				(*iterB)->IsPrevCollision = (*iterB)->IsCrntCollision;

				if (Math::CircleCollision((*iterA)->Position, (*iterA)->CircleRadius, (*iterB)->Position, (*iterB)->CircleRadius))
				{
					(*iterB)->IsCrntCollision = true;

					if ((*iterB)->IsCrntCollision && (*iterB)->IsPrevCollision)
					{
						(*iterB)->OnCollisionStay(*iterA);
						(*iterA)->OnCollisionStay(*iterB);
					}
					else if((*iterB)->IsCrntCollision && !(*iterB)->IsPrevCollision)
					{
						(*iterB)->OnCollisionEnter(*iterA);
						(*iterA)->OnCollisionEnter(*iterB);
					}
					continue;
				}
				(*iterB)->IsCrntCollision = false;
				
				if (!(*iterB)->IsPrevCollision)
				{
					(*iterB)->OnCollisionExit(*iterA);
					(*iterA)->OnCollisionExit(*iterB);
				}
			}
		}
	}
}

void ObjectManager::Update()
{
	if (!mNewObjects.empty())
	{
		for (auto iter : mNewObjects)
		{
			mCurObjects.emplace_back(iter);

			// ���̻� mNewObjects������ ������� �ʴ´�! �� �׷� �ǹ�
			SAFE_RELEASE(iter);
		}
	}
	mNewObjects.clear();

	if (mCurObjects.empty()) return;

	CollisionCheck(TAG::PLAYER, TAG::ENEMY);
	CollisionCheck(TAG::ENEMY, TAG::BULLET);

	for (auto iter = mCurObjects.begin(); iter != mCurObjects.end();)
	{
		if ((*iter)->IsDestory || (*iter)->IsOutMap())
		{
			SAFE_DELETE(*iter);

			// list�� Bidirectionaliterator(������� �������� ����)�̱� ������, 
			// ��! �ϰ� ���������� iterator�� ���� ��ҿ����� ������ �����ع�����
			// ������ erase�� ��ȯ���� ����Ѵ�. erase�� ��ȯ���� ������ ����� ���� ����̴�
			iter = mCurObjects.erase(iter);
			// mCurObjects.erase(iter++); �̷������� ����ϴ� ���� ����� ���� �ִµ�, 
			// �̹� iter�� erase�Լ��� ���� ������ �Ҿ��� ������ ���Ѱ��� ����Ű�Եȴ�
		}
		else if((*iter)->IsActive)
		{
			(*iter)->Update();
			//�ȵ�(*iter++)->Update();
			// Array[i++].Update();
		}
		iter++;
	}
}

void ObjectManager::Render()
{
	if (!mCurObjects.empty())
	{
		for (auto iter : mCurObjects)
		{
			if (iter->IsActive) iter->Render();
		}
	}
}
