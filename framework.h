#pragma once
#pragma comment(lib, "dsound.lib")

#include <SDKsound.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <list>
#include <map>

using namespace std;

using Matrix   = D3DXMATRIX;
using Matrix16 = D3DXMATRIXA16;
using Vector2  = D3DXVECTOR2;

const float GRAPH_CORRECTION = 45.f;
const float TO_RADIAN = 0.01745329f;
const float TO_DEGREE = 57.2957795f;
const float PI = 3.1415926535f;

const float ENEMY_DUMMY = 100.f;
const float PBULLET_DMG = 30.f;

const LPCWSTR TITLE = L"AAA";

const int WINSIZEX = 1600;
const int WINSIZEY =  900;

const int MAPSIZEMAXX =  2000;
const int MAPSIZEMINX = -2000;
const int MAPSIZEMAXY =  1600;
const int MAPSIZEMINY = -1600;

const int ATTACKKEY = VK_SPACE;

const D3DXVECTOR2  ZERO = D3DXVECTOR2( 0, 0);
const D3DXVECTOR2   ONE = D3DXVECTOR2( 1, 1);
const D3DXVECTOR2 RIGHT = D3DXVECTOR2( 1, 0);
const D3DXVECTOR2  LEFT = D3DXVECTOR2(-1, 0);
const D3DXVECTOR2  DOWN = D3DXVECTOR2( 0, 1);
const D3DXVECTOR2    UP = D3DXVECTOR2( 0,-1);

#define Dictionary map

#define DEVICE	   DXUTGetD3D9Device()
#define DELTA_TIME DXUTGetElapsedTime()
#define ELAPSED	   DXUTGetTime()

#define RANDOM(min, max) (rand() % ((max) + 1)) + min

struct Collider
{
	Vector2 leftTop, rightDown;

	void Init(Vector2 lTop = ZERO, Vector2 rDown = ZERO)
	{
		leftTop = lTop; rightDown = rDown;
	}
};

#include "Math.h"
#include "Singleton.h"
#include "Timer.h"
#include "Sound.h"
#include "Image.h"
#include "Particle.h"
#include "UI.h"
#include "Button.h"
#include "Banner.h"
#include "Scence.h"
#include "Input.h"
#include "Camera.h"
#include "Object.h"