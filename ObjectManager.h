#pragma once
#include "singleton.h"
#include "Object.h"

class ObjectManager :
	public singleton<ObjectManager>
{
	friend class Object;
public:
	ObjectManager();
	virtual ~ObjectManager();
	bool rendColRange = false;


	list<Object*> ObjList[RenderType::FINSH];

	Object* AddObject(const wstring& _Key, Object* _obj, Vector3 m_Pos, RenderType _renTag)
	{
		_obj->Init();
		_obj->renderType = _renTag;
		_obj->vPos = m_Pos;
		_obj->key = _Key;
		ObjList[_renTag].emplace_back(_obj);
		return _obj;
	}

	Object* FindObject(const wstring& _Key)
	{
		for (auto iter1 = 1; iter1 != RenderType::FINSH; iter1++)
			for (auto& iter2 : ObjList[iter1])
			{
				if (iter2->key == _Key)
				{
					return iter2;
				}
			}
		return nullptr;
	}

	void Update();
	void Render();
	void Release();
	void ClearAllObjects();
};

#define OBJECT ObjectManager::GetInstance()