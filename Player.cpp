#include "DXUT.h"
#include "Player.h"

void Player::Init()
{
	playerMesh = IMAGE->FindMesh(L"playerMesh");
	moveSpeed = 5000;
	rotSpeed = 5000;
	vSize = { 0.03f,0.03f ,0.03f };
}

void Player::Update()
{
	if (INPUT->KeyPress('W'))
	{
		MovePos(Vector3(0, 0, 1) * moveSpeed * D_TIME);
	}
	if (INPUT->KeyPress('S'))
	{
		MovePos(Vector3(0, 0, -1) * moveSpeed * D_TIME);
	}
	if (INPUT->KeyPress('A') && !moveD)
	{

		if (vRot.z <= 30)
			RotateRerpPos(Vector3(0, 0, 1) * rotSpeed * D_TIME, 3);
		vPos += Vector3(-0.02, 0, 0) * moveSpeed * D_TIME;

		moveA = true;
	}
	else moveA = false;
	if (INPUT->KeyPress('D') && !moveA)
	{
		if (vRot.z >= -30)
			RotateRerpPos(Vector3(0, 0, -1) * rotSpeed * D_TIME, 3);
		vPos += Vector3(0.01, 0, 0) * moveSpeed * D_TIME;
		moveD = true;
	}
	else moveD = false;

	if (!moveA && !moveD)
	{
		RotateRerpPos(Vector3(0, 0, 0), 3);
	}
	DEBUG_LOG(vRot.z);
}

void Player::Render()
{
	IMAGE->MeshRender(playerMesh, matWorld, true);
}

void Player::Release()
{
}

void Player::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void Player::onCollisionExit(Collider* col1, Collider* col)
{
}
