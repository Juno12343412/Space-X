#include "DXUT.h"
#include "Player.h"
#include "PlayerBullet.h"

void Player::Init()
{
	playerMesh = IMAGE->FindMesh(L"playerMesh");
	moveSpeed = 100;
	rotSpeed = 100;
	vSize = { 0.03f,0.03f ,0.03f };
	attackT = new Timer;
	attackT->SetTimer(0.3f);
	bodyCollider1 = new Collider;
	COLLISION->Register(bodyCollider1, this, vPos, 20, ColliderTag::PLAYER);
}

void Player::Update()
{
	bodyCollider1->colPos = vPos;
	if (INPUT->KeyPress('W'))
	{
		MovePos(Vector3(0, 0, 1) * moveSpeed);
	}
	if (INPUT->KeyPress('S'))
	{
		MovePos(Vector3(0, 0, -1) * moveSpeed);
	}
	if (INPUT->KeyPress('A') && !moveD)
	{

		if (vRot.z <= 30) {
			RotateRerpPos(Vector3(0, 0, 1) * rotSpeed, 3);
		}
		vPos += Vector3(-1, 0, 0) * moveSpeed * D_TIME;

		moveA = true;
	}
	else moveA = false;
	if (INPUT->KeyPress('D') && !moveA)
	{ 
		if (vRot.z >= -30) {
			RotateRerpPos(Vector3(0, 0, -1) * rotSpeed, 3); 
		}
		vPos += Vector3(1, 0, 0) * moveSpeed * D_TIME;
		moveD = true;
	}
	else moveD = false;

	if (INPUT->KeyPress('J'))
	{
		if (attackT->Update())
		{
			OBJECT->AddObject(L"PlayerBullet", new PlayerBullet, {vPos.x - 10, vPos.y , vPos.z}, RenderType::THREE);
			OBJECT->AddObject(L"PlayerBullet", new PlayerBullet, { vPos.x + 10, vPos.y , vPos.z }, RenderType::THREE);
		}
	}

	if (!moveA && !moveD)
	{
		RotateRerpPos(Vector3(0, 0, 0), 3);
	}
	DEBUG_LOG(vRot.z);
	MATH->Lerp<Vector3>(&CAMERA->m_vCameraPos, CAMERA->m_vCameraPos, Vector3(vPos.x, CAMERA->m_vCameraPos.y, vPos.z - 100), 3);
}

void Player::Render()
{
	IMAGE->MeshRender(playerMesh, matWorld, true);
}

void Player::Release()
{
	SAFE_DELETE(attackT);
	bodyCollider1->isDestroy = true;
}

void Player::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void Player::onCollisionStay(Collider* col1, Collider* col2)
{
}

void Player::onCollisionExit(Collider* col1, Collider* col)
{
}
