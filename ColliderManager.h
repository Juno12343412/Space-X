#pragma once
#include "singleton.h"
#include "Collider.h"

class Collider;

class ColliderManager
	:public singleton<ColliderManager>
{
public:
	ColliderManager();
	virtual ~ColliderManager();

	bool collisionTag[ColliderTag::END + 1][ColliderTag::END + 1];

	void Register(Collider* col, Object* _parent, Vector3 pos, float radius, ColliderTag Tag);
	void UnRegister(Collider* col);

	list<Collider*> colliderList;

	void Update();
};

#define COLLISION ColliderManager::GetInstance()