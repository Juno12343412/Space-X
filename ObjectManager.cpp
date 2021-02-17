#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::Update()
{
	for (int i = RenderType::FIRST + 1; i < RenderType::FINSH; i++)
	{
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();)
		{
			if ((*iter)->CheckDestroy())
			{
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = ObjList[i].erase(iter);
			}
			else
			{
				(*iter)->Update();
				iter++;
			}
		}
	}
	COLLISION->Update();
	if (INPUT->KeyDown(VK_F11))
	{
		rendColRange = !rendColRange;
	}
}

void ObjectManager::Render()
{
	for (int i = RenderType::FIRST + 1; i < RenderType::FINSH; i++)
	{
		for (auto iter : ObjList[i]) {
			iter->TransformUpdate();
			iter->Render();
		}
		if (i == RenderType::TWO)
		{
			for (auto iter : COLLISION->colliderList)
			{
				if (iter->isActive)
					iter->RangeRender();
			}
		}
	}

}

void ObjectManager::Release()
{
	for (int i = RenderType::FIRST + 1; i < RenderType::FINSH; i++)
	{
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();)
		{
			if ((*iter) == nullptr)
				iter++;
			(*iter)->Release();
			SAFE_DELETE(*iter);
			iter++;
		}
	}
}

void ObjectManager::ClearAllObjects()
{
	for (int i = RenderType::FIRST + 1; i < RenderType::FINSH; i++) {
		for (auto iter : ObjList[i])
		{
			iter->isDestroy = true;
		}
	}
}
