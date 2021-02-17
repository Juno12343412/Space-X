#include "DXUT.h"
#include "SceneManager.h"
#include "Scene.h"


SceneManager::SceneManager()
	:nowScene(nullptr), nextScene(nullptr)
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::Release()
{
	if (nowScene) nowScene->Release();

	for (auto iter : scenes) SAFE_DELETE(iter.second);

	scenes.clear();
}

Scene* SceneManager::AddScene(const string& key, Scene* scenePtr)
{
	if (!scenePtr) return nullptr;

	if (scenes.find(key) != scenes.end()) return nullptr;

	scenes.insert(make_pair(key, scenePtr));
	return scenePtr;
}

Scene* SceneManager::ChangeScene(const string& key)
{
	auto find = scenes.find(key);
	if (find == scenes.end()) return nullptr;

	OBJECT->ClearAllObjects();

	nextScene = find->second;
	return nextScene;
}

void SceneManager::Update()
{
	if (nextScene)
	{
		if (nowScene) nowScene->Release();
		nextScene->Init();
		nowScene = nextScene;
		nextScene = nullptr;
	}
	if (nowScene) nowScene->Update();
}

void SceneManager::Render()
{
	if (nowScene) nowScene->Render();
}
