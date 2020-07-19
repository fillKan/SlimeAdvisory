#pragma once

enum class TAG
{
	PLAYER, ENEMY, EBULLET, PBULLET, NONE
};

class Object abstract
{
public:

	Object* Parent;
	Object* Child;

	string Name;
	TAG Tag;

	bool IsDestory;
	bool IsActive;

	bool IsPrevCollision;
	bool IsCrntCollision;

	float Rotation;
	float CircleRadius;
	
	float MAXHealth = 1.f;
	float CURHealth = 1.f;

	Vector2 Position;
	Vector2 Scale;
	Vector2 Velocity;
	Vector2 Direction;

public:
			 Object();
	virtual ~Object();

	virtual void Init   () PURE;
	virtual void Update () PURE;
	virtual void Render () PURE;
	virtual void Release() PURE;

	virtual void OnCollisionEnter(Object* other) PURE;
	virtual void OnCollisionStay (Object* other) PURE;
	virtual void OnCollisionExit (Object* other) PURE;

	bool IsOutMap()
	{
		return (Position.x > WINSIZEX + SCREEN_OFFSET || Position.x < -SCREEN_OFFSET ||
				Position.y > WINSIZEY + SCREEN_OFFSET || Position.y < -SCREEN_OFFSET);
	}

	void HealthInit(float max);
};

class ObjectManager : public Singleton<ObjectManager>
{
public:
	 ObjectManager();
	~ObjectManager();

	void AddObject(Object* object);

	Object* FindObject  (const string& name);
	Object* operator [] (const string& name) { return FindObject(name); }

	Object* FindObject  (TAG tag);
	Object* operator [] (TAG tag)			 { return FindObject(tag); }

	deque<Object*> FindObjects (TAG tag);

	Object* FindPlayer();
	Object* ForwardCloest(Vector2 parePos, TAG targetTAG);

	void CollisionCheck(TAG tagA, TAG tagB);

public: 
	void Update ();
	void Render ();
	void Release();
private:
	list<Object*> mNewObjects;
	list<Object*> mCurObjects;

	Object* mPlayer;
};
#define OBJECT ObjectManager::Instance()