#include "DXUT.h"
#include "Collider.h"

Collider::Collider()
{
	img = IMAGE->FindImage(L"colRange");
}

Collider::~Collider()
{
}

void Collider::OnEnterCollision(Collider* col1, Collider* col2)
{
	parent->onCollisionEnter(col1, col2);
}

void Collider::OnExitCollision(Collider* col1, Collider* col2)
{
	parent->onCollisionExit(col1, col2);
}

void Collider::RangeRender()
{
	if (OBJECT->rendColRange) {
		IMAGE->ReBegin(false, true);
		img->CenterRender(colPos, 0, Vector3((colRadius * 2) / 100, (colRadius * 2) / 100, 1), D3DCOLOR_RGBA(255, 255, 255, 100));
		IMAGE->ReBegin(false, false);
	}
}
