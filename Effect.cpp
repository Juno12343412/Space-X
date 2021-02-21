#include "DXUT.h"
#include "Effect.h"

Effect::Effect(CMeshLoader* effectMesh)
	:effectMesh(effectMesh)
{
}

Effect::~Effect()
{
}

void Effect::Init()
{
}

void Effect::Update()
{
}

void Effect::Render()
{
	IMAGE->MeshRender(effectMesh, matWorld, true);
}

void Effect::Release()
{
}

void Effect::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void Effect::onCollisionStay(Collider* col1, Collider* col2)
{
}

void Effect::onCollisionExit(Collider* col1, Collider* col)
{
}
