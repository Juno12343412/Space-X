#include "DXUT.h"
#include "MainGame.h"
#include "LoadingScene.h"
#include "Stage1.h"
void MainGame::Init()
{
	SCENE->AddScene("loading", new LoadingScene);
	SCENE->AddScene("stage1", new Stage1);
	SCENE->ChangeScene("loading");
}

void MainGame::Update()
{
	CAMERA->Update();
	SCENE->Update();
	INPUT->Update();
	OBJECT->Update();
	COLLISION->Update();
}

void MainGame::Render()
{
	CAMERA->SetTransform();
	IMAGE->Begin(false, false);

	SCENE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	SceneManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	ImageManager::ReleaseInstance();
	SoundManager::ReleaseInstance();
	MathManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	ColliderManager::ReleaseInstance();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}
