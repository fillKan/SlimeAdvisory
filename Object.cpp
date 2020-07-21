#include "DXUT.h"
#include "Object.h"

#include "Player.h"

Object::Object() : Parent(nullptr), Child(nullptr), Name(""), Tag(TAG::NONE), IsDestory(false), IsActive(true), IsPrevCollision(false), IsCrntCollision(false), Rotation(0.0f), Position(ZERO), Direction(ZERO), CircleRadius(0.f)
{
}

Object::~Object()
{
}

ObjectManager::ObjectManager() : mPlayer(nullptr)
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(Object* object)
{
	object->Init();

	if (object->Tag == TAG::PLAYER)
	{
		mPlayer = object;
	}
	mObjects.emplace_back(object);
}

Object* ObjectManager::FindObject(const string& name)
{
	for (auto iter : mObjects)
	{
		if (iter->Name == name) return iter;
	}
	return nullptr;
}

Object* ObjectManager::FindObject(TAG tag)
{
	for (auto iter : mObjects)
	{
		if (iter->Tag == tag) return iter;
	}
	return nullptr;
}

deque<Object*> ObjectManager::FindObjects(TAG tag)
{
	deque<Object*> objects;

	for (auto iter : mObjects)
	{
		if (iter->Tag == tag)
		{
			objects.push_back(iter);
		}
	}
	return objects;
}

Object** ObjectManager::FindBosses()
{
	char name[8];
	Object* findBoss[3] = { nullptr };

	for (int i = 1; i <= 3; ++i)
	{
		sprintf(name, "MBoss%d", i);

		findBoss[i - 1] = OBJECT->FindObject(name);
	}
	return findBoss;
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

	for (auto iter : mObjects)
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
	if (mObjects.empty()) return;

	for (auto& iterA = mObjects.begin(); iterA != mObjects.end(); iterA++)
	{
		if ((*iterA)->Tag != tagA) continue;

		for (auto& iterB = mObjects.begin(); iterB != mObjects.end(); iterB++)
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
	if (mObjects.empty()) return;

	CollisionCheck(TAG::PLAYER, TAG::EBULLET);
	CollisionCheck(TAG::ENEMY, TAG::PBULLET);

	for (auto iter = mObjects.begin(); iter != mObjects.end();)
	{
		if ((*iter)->IsActive) (*iter)->Update();

		if ((*iter)->IsDestory || (*iter)->IsOutMap() || (*iter)->CURHealth <= 0.f)
		{
			if ((*iter)->Tag == TAG::ENEMY && (*iter)->CURHealth <= 0.f)
			{
				mPlayerKillEnemy++;
			}
			if ((*iter)->Tag != TAG::PLAYER)
			{
				SAFE_DELETE(*iter);
			}
			iter = mObjects.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void ObjectManager::Render()
{
	if (!mObjects.empty())
	{
		for (auto iter : mObjects)
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

void ObjectManager::Release()
{
	for (auto iter : mObjects)
	{
		if (iter->Tag == TAG::PLAYER)
		{
			mPlayer = nullptr;
		}
		iter->Release();

		SAFE_DELETE(iter);
	}
	mObjects.clear();

	if (mPlayer != nullptr)
	{
		SAFE_DELETE(mPlayer);
	}
}

void Object::HealthInit(float max)
{
	MAXHealth = max;
	CURHealth = max;
}
