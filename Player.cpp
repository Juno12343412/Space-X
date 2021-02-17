#include "DXUT.h"
#include "Player.h"

void Player::Init()
{
	playerMesh = IMAGE->FindMesh(L"playerMesh");
	moveSpeed = 500;
	rotSpeed = 50;
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
	if (INPUT->KeyPress('A'))
	{
		if (vRot.z >= -100)
			RotatePos(Vector3(0, 0, -1) * rotSpeed * D_TIME);
		if (vPos.z <= -50)
			MovePos(Vector3(-1, 0, 0) * moveSpeed * D_TIME);
		moveA = true;
	}
	else moveA = false;
	if (INPUT->KeyPress('D'))
	{
		if (vRot.z <= 100)
			RotatePos(Vector3(0, 0, 1) * rotSpeed * D_TIME);
		if (vPos.z >= 50)
			MovePos(Vector3(1, 0, 0) * moveSpeed * D_TIME);
		moveD = true;
	}
	else moveD = false;

	if (!moveA && !moveD)
	{
		RotateRerpPos(Vector3(0, 0, 0), 1);
	}
}

void Player::Render()
{
	IMAGE->MeshRender(playerMesh, matWorld, false);
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
