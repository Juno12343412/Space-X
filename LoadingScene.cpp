#include "DXUT.h"
#include "LoadingScene.h"

void LoadingScene::Init()
{
	CAMERA->Reset();
	SOUND->AddSound("SettRStart", L"./Resource/Sound/SettRStart.wav");
	SOUND->AddSound("SettRFinsh", L"./Resource/Sound/SettRFinsh.wav");
	SOUND->AddSound("SettBuff", L"./Resource/Sound/SettBuff.wav");
	ImageLoad(L"SettIdle", L"Player/Animations/Idle", Type::LTHREE, 15);
	ImageLoad(L"SettRun", L"Player/Animations/Run", Type::LTHREE, 15);
	ImageLoad(L"SettAttack1", L"Player/Animations/Attack1", Type::LTHREE, 30);
	ImageLoad(L"SettAttack2", L"Player/Animations/Attack2", Type::LTHREE, 30);
	ImageLoad(L"SettAttackR", L"Player/Animations/AttackR", Type::LTHREE, 27);
	ImageLoad(L"GrassBlock", L"Blocks/GrassBlock", Type::LTHREE);
	ImageLoad(L"colRange", L"colRange", Type::LTWO);
}

void LoadingScene::Update()
{
	if (!Imagelist.empty())
	{
		auto info = Imagelist.front();
		IMAGE->AddImage(info.m_Key, info.m_Path);
		Imagelist.pop_front();
		ImageCount++;
	}
	if (!Anilist.empty())
	{
		auto info = Anilist.front();
		IMAGE->ADDVECIMAGE(info.m_Key, info.m_Path, info.m_Size);
		Anilist.pop_front();
		ImageCount++;
	}
	if (!Meshlist.empty())
	{
		auto info = Meshlist.front();
		IMAGE->AddMesh(info.m_Key, info.m_Path);
		Meshlist.pop_front();
		ImageCount++;
	}
	if (!MeshAnilist.empty())
	{
		auto info = MeshAnilist.front();
		IMAGE->ADDVECMESH(info.m_Key, info.m_Path, info.m_Size);
		MeshAnilist.pop_front();
		ImageCount++;
	}
	if (Anilist.empty() && Imagelist.empty() && Meshlist.empty() && MeshAnilist.empty())
	{
		SCENE->ChangeScene("test");
	}
}

void LoadingScene::Render()
{
	IMAGE->ReBegin(true, false);
	WCHAR a[12];
	wsprintf(a, L"·ÎµùÁß..");
	IMAGE->TextDraw(a, Vector3(WINSIZEX / 2 - 20, WINSIZEY / 2, 0), 200, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->ReBegin(false, false);
}

void LoadingScene::Release()
{
}

void LoadingScene::ImageLoad(const wstring& _Key, const wstring& _Path, Type tp, int size)
{
	if (tp == Type::LTWO) {
		if (size == 0)
		{
			Imagelist.push_back(Load(_Key, _Path));
			maxImageCount++;
		}
		else
		{
			Anilist.push_back(Load(_Key, _Path, size));
			maxImageCount++;
		}
	}
	else
	{
		if (size == 0)
		{
			Meshlist.push_back(Load(_Key, _Path));
			maxImageCount++;
		}
		else
		{
			MeshAnilist.push_back(Load(_Key, _Path, size));
			maxImageCount++;
		}
	}
}
