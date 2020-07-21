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
#include <deque>

using namespace std;

enum class MBOSS_PATTERN
{
	NONE = -1,
	APPER, BOMBING, DASH, END
};

using Matrix   = D3DXMATRIX;
using Matrix16 = D3DXMATRIXA16;
using Vector2  = D3DXVECTOR2;

const float GRAPH_CORRECTION = 45.f;
const float TO_RADIAN = 0.01745329f;
const float TO_DEGREE = 57.2957795f;
const float PI = 3.1415926535f;

const float SCREEN_OFFSET = 120.f;

const float ENEMY_DUMMY = 100.f;
const float PBULLET_DMG = 30.f;
const float MBOSS_MAXHP = 550.f;

const UINT MBOSS_APPER_NEED = 15;

const LPCWSTR TITLE = L"AAA";

const int WINSIZEX = 1600;
const int WINSIZEY =  900;

const int MAPSIZEMAXX =  2000;
const int MAPSIZEMINX = -2000;
const int MAPSIZEMAXY =  1600;
const int MAPSIZEMINY = -1600;

const int ATTACKKEY = VK_SPACE;

const int    MBOSS_COUNT = 3;
const string MBOSS_NAME  = "MBoss";

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

#include "Math.h"
#include "Singleton.h"
#include "Timer.h"
#include "Sound.h"
#include "Image.h"
#include "Particle.h"
#include "Skill.h"
#include "UI.h"
#include "Button.h"
#include "Banner.h"
#include "Scence.h"
#include "Input.h"
#include "Camera.h"
#include "Object.h"