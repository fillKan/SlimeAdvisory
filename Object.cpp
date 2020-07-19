#include "DXUT.h"
#include "Object.h"

#include "Player.h"

Object::Object() : Parent(nullptr), Child(nullptr), Name(""), Tag(TAG::NONE), IsDestory(false), IsActive(true), IsPrevCollision(false), IsCrntCollision(false), Rotation(0.0f), Position(ZERO), Scale(ONE), Velocity(ZERO), Direction(ZERO), CircleRadius(0.f)
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

	SAFE_DELETE(mPlayer);
}

void ObjectManager::AddObject(Object* object)
{
	object->Init();

	if (object->Tag == TAG::PLAYER)
	{
		mPlayer = object;
	}
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

deque<Object*> ObjectManager::FindObjects(TAG tag)
{
	deque<Object*> objects;

	for (auto iter : mCurObjects)
	{
		if (iter->Tag == tag)
		{
			objects.push_back(iter);
		}
	}
	return objects;
}

Object* ObjectManager::FindPlayer()
{
	return mPlayer;
}

Object* ObjectManager::ForwardCloest(Vector2 parePos, TAG targetTAG)
{
	float compareDistance;

	float   cloestDistance = 160000.f;
	Object* cloestObj	   = nullptr;

	for (auto iter : mCurObjects)
	{
		if (iter->IsActive && iter->Tag == targetTAG)
		{
			if (iter->Position.x > parePos.x)
			{
				compareDistance = Math::Distance(iter->Position, parePos);

				if (compareDistance < cloestDistance)
				{
					float temp = compareDistance;
					compareDistance = cloestDistance;
					cloestDistance = temp;

					cloestObj = iter;
				}
			}
		}
	}
	return cloestObj;
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

			(*iterB)->IsPrevCollision = (*iterB)->IsCrntCollision;

			if (Math::CircleCollision((*iterA)->Position, (*iterA)->CircleRadius, (*iterB)->Position, (*iterB)->CircleRadius))
			{
				(*iterB)->IsCrntCollision = true;

				if ((*iterB)->IsCrntCollision && (*iterB)->IsPrevCollision)
				{
					(*iterB)->OnCollisionStay(*iterA);
					(*iterA)->OnCollisionStay(*iterB);
				}
				else if ((*iterB)->IsCrntCollision && !(*iterB)->IsPrevCollision)
				{
					(*iterB)->OnCollisionEnter(*iterA);
					(*iterA)->OnCollisionEnter(*iterB);
				}
			}
			else
			{
				(*iterB)->IsCrntCollision = false;

				if ((*iterB)->IsPrevCollision)
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

			SAFE_RELEASE(iter);
		}
	}
	mNewObjects.clear();

	if (mCurObjects.empty()) return;

	CollisionCheck(TAG::PLAYER, TAG::EBULLET);
	CollisionCheck(TAG::ENEMY, TAG::PBULLET);

	for (auto iter = mCurObjects.begin(); iter != mCurObjects.end();)
	{
		if ((*iter)->IsActive) (*iter)->Update();

		if ((*iter)->IsDestory || (*iter)->IsOutMap() || (*iter)->CURHealth <= 0.f)
		{
			if ((*iter)->Tag != TAG::PLAYER)
			{
				SAFE_DELETE(*iter);
			}
			// list�� Bidirectionaliterator(������� �������� ����)�̱� ������, 
			// ��! �ϰ� ���������� iterator�� ���� ��ҿ����� ������ �����ع�����
			// ������ erase�� ��ȯ���� ����Ѵ�. erase�� ��ȯ���� ������ ����� ���� ����̴�
			iter = mCurObjects.erase(iter);
			// mCurObjects.erase(iter++); �̷������� ����ϴ� ���� ����� ���� �ִµ�, 
			// �̹� iter�� erase�Լ��� ���� ������ �Ҿ��� ������ ���Ѱ��� ����Ű�Եȴ�
		}
		else
		{
			//�ȵ�(*iter++)->Update();
			// Array[i++].Update();

			iter++;
		}
	}
}

void ObjectManager::Render()
{
	if (!mCurObjects.empty())
	{
		for (auto iter : mCurObjects)
		{
			if (iter->IsActive && !iter->Parent)
			{
				if (iter->Child)
				{
					iter->Child->Render();
				}
				iter->Render();
			}
		}
	}
}

void Object::HealthInit(float max)
{
	MAXHealth = max;
	CURHealth = max;
}
