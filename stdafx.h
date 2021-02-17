#pragma once
#pragma comment(lib,"legacy_stdio_definitions.lib")
#pragma comment(lib,"dsound.lib")
#pragma comment (linker, "/entry:wWinMainCRTStartup /subsystem:console")
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <string>

#pragma region usings

using namespace std;
using Vector2 = D3DXVECTOR2;
using Vector3 = D3DXVECTOR3;
using Vector4 = D3DXVECTOR4;
using Matrix = D3DXMATRIX;

#pragma endregion

#pragma region defines

#define g_device DXUTGetD3D9Device()
#define D_TIME DXUTGetElapsedTime() * timeScale

#ifdef _DEBUG()
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log) cout << log << endl;
#endif

#pragma endregion

#pragma region variables

const int WINSIZEX = 1920;
const int WINSIZEY = 1080;

static bool isWindowed = true;
static float timeScale = 1;
static float gravityScale = 1;

#pragma endregion

#pragma region includes

#include "ImageManager.h"
#include "CameraManager.h"
#include "MathManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "Timer.h"
#include "ObjectManager.h"
#include "ColliderManager.h"

#pragma endregion 