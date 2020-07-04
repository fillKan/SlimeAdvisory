#pragma once

enum class TAG
{
	PLAYER, ENEMY, EBULLET, PBULLET, NONE
};

class Object abstract
{
public:

	Object* Parent;

	string Name;
	TAG Tag;

	bool IsDestory;
	bool IsActive;

	bool IsPrevCollision;
	bool IsCrntCollision;

	float Rotation;
	float CircleRadius;
	float Health;

	Vector2 Position;
	Vector2 Scale;
	Vector2 Velocity;
	Vector2 ImageSize;

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
		return (Position.x > MAPSIZEMAXX || Position.x < MAPSIZEMINX || 
				Position.y < MAPSIZEMINY || Position.y > MAPSIZEMAXY);
	}
};

class ObjectManager : public Singleton<ObjectManager>
{
public:
	 ObjectManager() {};
	~ObjectManager();

	void AddObject(Object* object);

	Object* FindObject  (const string& name);
	Object* operator [] (const string& name) { return FindObject(name); }

	Object* FindObject  (TAG tag);
	Object* operator [] (TAG tag)			 { return FindObject(tag); }

	void CollisionCheck(TAG tagA, TAG tagB);

public: 
	void Update();
	void Render();
private:
	list<Object*> mNewObjects;
	list<Object*> mCurObjects;
};
#define OBJECT ObjectManager::Instance()