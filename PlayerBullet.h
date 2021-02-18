#pragma once
#include "Object.h"
class PlayerBullet :
    public Object
{
    CMeshLoader* bulletMesh = nullptr;
    float moveSpeed;
    Collider* bulletCollider = nullptr;
    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionEnter(Collider* col1, Collider* col2) override;
    virtual void onCollisionExit(Collider* col1, Collider* col) override;
};

