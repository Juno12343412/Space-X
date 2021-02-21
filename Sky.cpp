#include "DXUT.h"
#include "Sky.h"

void Sky::Init()
{
	skyMesh = IMAGE->FindMesh(L"spaceSky");
	vSize = { 10,10,10 };
}

void Sky::Update()
{
	RotatePos(Vector3(10,0,0));
}

void Sky::Render()
{
	IMAGE->MeshRender(skyMesh, matWorld, true);
}

void Sky::Release()
{
}

void Sky::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void Sky::onCollisionStay(Collider* col1, Collider* col2)
{
}
void Sky::onCollisionExit(Collider* col1, Collider* col)
{
}

