#include "DXUT.h"
#include "Object.h"
#include "Collider.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::TransformUpdate()
{
	if (isGravity) {
		vPos.y -= gravityScale * D_TIME;
		if (vPos.y <= 0 + objHeight)
			vPos.y += gravityScale * D_TIME;
	}


	Matrix scale, rotation[3], position;
	D3DXMatrixScaling(&scale, vSize.x, vSize.y, vSize.z);
	D3DXMatrixTranslation(&position, vPos.x, vPos.y, vPos.z);

	D3DXMatrixRotationX(&rotation[0], D3DXToRadian(vRot.x));
	D3DXMatrixRotationY(&rotation[1], D3DXToRadian(vRot.y));
	D3DXMatrixRotationZ(&rotation[2], D3DXToRadian(vRot.z));

	R = rotation[0] * rotation[1] * rotation[2];

	matWorld = scale * R * position;
}

void Object::MovePos(Vector3 pos)
{
	Vector3 vecDir = pos;
	D3DXVec3TransformNormal(&vecDir, &vecDir, &R);
	vPos += vecDir * D_TIME;
}

void Object::RotatePos(Vector3 rot)
{
	vRot += rot * D_TIME;
}

void Object::RotateRerpPos(Vector3 rot, float time)
{
	MATH->Lerp<Vector3>(&vRot, rot, rot, time);
}

void Object::SetPos(Vector3 pos)
{
	vPos = pos;
}

void Object::SetRotate(Vector3 rot)
{
	vRot = rot;
}
