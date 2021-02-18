#include "DXUT.h"
#include "PlayerBullet.h"

void PlayerBullet::Init()
{
	bulletMesh = IMAGE->FindMesh(L"bullet");
	moveSpeed = 1000;
	vSize = { 0.3f,0.3f, 0.3f };
	bulletCollider = new Collider;
	COLLISION->Register(bulletCollider, this, vPos, 5, ColliderTag::PLAYERATTACK);
}

void PlayerBullet::Update()
{
	bulletCollider->colPos = vPos;
	MovePos(Vector3(0, 0, 100) * moveSpeed * D_TIME);
	if (vPos.z >= 1000) isDestroy = true;
}

void PlayerBullet::Render()
{
	IMAGE->MeshRender(bulletMesh, matWorld, true);
}

void PlayerBullet::Release()
{
}

void PlayerBullet::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void PlayerBullet::onCollisionExit(Collider* col1, Collider* col)
{
}
