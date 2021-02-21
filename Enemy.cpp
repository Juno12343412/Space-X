#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy(int kind)
	:kind(kind)
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	switch (kind)
	{
	case 1:
		enemyMesh = IMAGE->FindMesh(L"playerMesh");
		attackT = new Timer;
		bodyCollider1 = new Collider;
		COLLISION->Register(bodyCollider1, this, vPos, 20, ColliderTag::ENEMY);
		hp = 100;
		vSize = { 0.03f,0.03f ,0.03f };
		vRot = { 0,180,0 };
		break;
	}
}

void Enemy::Update()
{
	switch (kind)
	{
	case 1:
		bodyCollider1->colPos = vPos;
		break;
	}
	if (hp <= 0)
		isDestroy = true;
}

void Enemy::Render()
{
	IMAGE->MeshRender(enemyMesh, matWorld, true);
}

void Enemy::Release()
{
	SAFE_DELETE(attackT);
	bodyCollider1->isDestroy = true;
}

void Enemy::onCollisionEnter(Collider* col1, Collider* col2)
{
	switch (col1->colTag)
	{
	case ColliderTag::ENEMY:
		switch (col2->colTag)
		{
		case ColliderTag::PLAYERBULLET1:
			col1->parent->hp -= col2->parent->damage;
			break;
		}
		break;
	}
}

void Enemy::onCollisionStay(Collider* col1, Collider* col2)
{
}

void Enemy::onCollisionExit(Collider* col1, Collider* col)
{
}
