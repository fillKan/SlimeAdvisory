#pragma once
template<typename T>
class Singleton
{
private:
	static T* mInstance;

public:
	static T* Instance()
	{
		if (!mInstance)
		{
			mInstance = new T();
		}
		return mInstance;
	}
	static void ReleaseInstance()
	{
		SAFE_DELETE(mInstance);
	}
};
template<typename T>
T* Singleton<T>::mInstance = nullptr;