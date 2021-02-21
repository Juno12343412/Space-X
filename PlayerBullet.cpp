#include "DXUT.h"
#include "PlayerBullet.h"

void PlayerBullet::Init()
{
	bulletMesh = IMAGE->FindMesh(L"bullet");
	moveSpeed = 300;
	vSize = { 0.3f,0.3f, 0.3f };
	bulletCollider = new Collider;
	COLLISION->Register(bulletCollider, this, vPos, 5, ColliderTag::PLAYERBULLET1);
	damage = 50;
}

void PlayerBullet::Update()
{
	bulletCollider->colPos = vPos;
	MovePos(Vector3(0, 0, 1) * moveSpeed);
	if (vPos.z >= 1000) isDestroy = true;
}

void PlayerBullet::Render()
{
	IMAGE->MeshRender(bulletMesh, matWorld, true);
}

void PlayerBullet::Release()
{
	bulletCollider->isDestroy = true;
}

void PlayerBullet::onCollisionEnter(Collider* col1, Collider* col2)
{
	switch (col1->colTag)
	{
	case ColliderTag::PLAYERBULLET1:
		switch (col2->colTag)
		{
		case ColliderTag::ENEMY:
			isDestroy = true;
			break;
		}
		break;
	}
}

void PlayerBullet::onCollisionStay(Collider* col1, Collider* col2)
{
}

void PlayerBullet::onCollisionExit(Collider* col1, Collider* col)
{
}
