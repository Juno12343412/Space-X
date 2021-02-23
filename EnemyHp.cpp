#include "DXUT.h"
#include "EnemyHp.h"

EnemyHp::EnemyHp(int num)
	:num(num)
{
}

EnemyHp::~EnemyHp()
{
}

void EnemyHp::Init()
{
	//img = IMAGE->FindImage(L"EnemyHp");
}

void EnemyHp::Update()
{
}

void EnemyHp::Render()
{
	IMAGE->Render(img, vPos, 0, { 1,1,1 }, {1,1,num,num});
}

void EnemyHp::Release()
{
}

void EnemyHp::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void EnemyHp::onCollisionStay(Collider* col1, Collider* col2)
{
}

void EnemyHp::onCollisionExit(Collider* col1, Collider* col)
{
}
