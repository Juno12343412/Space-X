#include "DXUT.h"
#include "ColliderManager.h"
#include "Collider.h"
#include "Object.h"

ColliderManager::ColliderManager()
	:collisionTag{
		{ 0,0,0,0,0,0,0,0 }, // NONE 1
		{ 0,0,0,0,1,0,0,0 }, // ENEMY 2
		{ 0,0,0,1,0,0,0,0 }, // ENEMYATTACK 3
		{ 0,0,1,0,0,0,0,0 }, // PLAYER 4
		{ 0,1,0,0,0,0,0,0 }, // PLAYERATTACK 5
		{ 0,0,0,0,0,0,1,0 }, // UI 6
		{ 0,0,0,0,0,1,0,0 }, // MOUSE 7
		{ 0,0,0,0,0,0,0,0 }, // END 8
}
{
}

ColliderManager::~ColliderManager()
{
}

void ColliderManager::Register(Collider* col, Object* _parent, Vector3 pos, float radius, ColliderTag Tag)
{
	col->parent = _parent;
	col->colPos = pos;
	col->colRadius = radius;
	col->colTag = Tag;
	colliderList.push_back(col);
}

void ColliderManager::UnRegister(Collider* col)
{
	colliderList.remove(col);
}

void ColliderManager::Update()
{
	if (colliderList.size() < 2)
		return;

	for (auto iter1 : colliderList)
	{
		for (auto iter2 : colliderList)
		{
			if (iter1 == iter2 || !iter1->isActive || !iter2->isActive)
				continue;
			if (iter1->isDestroy || iter1->parent->isDestroy) {
				colliderList.remove(iter1);
				return;
			}
			if (iter2->isDestroy || iter2->parent->isDestroy) {
				colliderList.remove(iter2);
				return;
			}

			if (collisionTag[iter1->colTag][iter2->colTag])
			{
				float length = (D3DXVec3Length(&(iter1->colPos - iter2->colPos)));
				if (length < (iter1->colRadius + iter2->colRadius))
				{
					if (!iter1->isEnter) {
						iter1->OnEnterCollision(iter1, iter2);
						iter1->isEnter = true;
					}
					else
					{
						iter1->OnStayCollision(iter1, iter2);
					}
				} 
				else
				{
					if (iter1->isEnter) {
						iter1->OnExitCollision(iter1, iter2);
						iter1->isEnter = false;
					}
				}
			}
		}
	}
}