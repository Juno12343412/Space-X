#include "DXUT.h"
#include "Stage1.h"
#include "Player.h"
#include "Sky.h"
#include "Enemy.h"

void Stage1::Init()
{
	CAMERA->Reset();
	OBJECT->AddObject(L"player", new Player, Vector3(0, 0, 0), RenderType::THREE);
	OBJECT->AddObject(L"enemy", new Enemy(1), Vector3(0, 0, 100), RenderType::THREE);
	OBJECT->AddObject(L"enemy", new Enemy(1), Vector3(100, 0, 100), RenderType::THREE);
	OBJECT->AddObject(L"enemy", new Enemy(1), Vector3(-100, 0, 100), RenderType::THREE);
	OBJECT->AddObject(L"sky", new Sky, Vector3(0, 0, 0), RenderType::THREE);
}

void Stage1::Update()
{

}

void Stage1::Render()
{
}

void Stage1::Release()
{
}
