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

const int WINSIZEX = 1280;
const int WINSIZEY =  720;

const int MAPSIZEMAXX =  2000;
const int MAPSIZEMINX = -2000;
const int MAPSIZEMAXY =  1600;
const int MAPSIZEMINY = -1600;

const D3DXVECTOR2 ZERO = D3DXVECTOR2(0, 0);
const D3DXVECTOR2  ONE = D3DXVECTOR2(1, 1);

#define Dictionary map

#define DEVICE	   DXUTGetD3D9Device()
#define DELTA_TIME DXUTGetElapsedTime()
#define ELAPSED	   DXUTGetTime()

#define RANDOM(min, max) rand() % ((max) + 2) + (min)

#include "Math.h"
#include "Singleton.h"
#include "Timer.h"
#include "Sound.h"
#include "Scence.h"
#include "Input.h"
#include "Image.h"
#include "Camera.h"
#include "Object.h"