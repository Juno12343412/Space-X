#pragma once
#include "Scene.h"
enum Type
{
	LTWO,
	LTHREE
};

struct Load
{
public:
	Load(const wstring& _Key, const wstring& _Path, int Size = 0) : m_Key(_Key), m_Path(_Path), m_Size(Size) { }
	~Load() {}
public:
	wstring m_Key;
	wstring m_Path;
	int m_Size = 0;
};

class LoadingScene :
	public Scene
{
public:
	virtual void Init()			override;
	virtual void Update()		override;
	virtual void Render()		override;
	virtual void Release()		override;
	void ImageLoad(const wstring& _Key, const wstring& _Path, Type tp, int size = 0);
	int ImageCount = 0;
	int maxImageCount = 0;
	list<Load> Imagelist;
	list<Load> Anilist;
	list<Load> Meshlist;
	list<Load> MeshAnilist;
	texture* LoadingBar;
};

