#pragma once
class Scence abstract
{
public:
			 Scence() {};
	virtual ~Scence() {};

	virtual void Init   () PURE;
	virtual void Update () PURE;
	virtual void Render () PURE;
	virtual void Release() PURE;
};

class ScenceManager : public Singleton<ScenceManager>
{
private:
	Dictionary<string, Scence*> mScences;

	Scence* mCurrentScence;
	Scence* mNextScence;

public:
	 ScenceManager();
	~ScenceManager();

	 void  AddScence(const string& key, Scence* scence);
	 void LoadScence(const string& key);

	 void Update();
	 void Render();

private:

	void Release();
};
#define SCENCE ScenceManager::Instance()