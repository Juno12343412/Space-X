#include "DXUT.h"
#include "Stage1.h"
#include "Player.h"

void Stage1::Init()
{
	CAMERA->Reset();
	OBJECT->AddObject(L"player", new Player, Vector3(0, 0, 100), RenderType::THREE);
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
