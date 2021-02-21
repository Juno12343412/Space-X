#pragma once
#include "Object.h"
class Enemy :
    public Object
{
public:
    Enemy(int kind);
    virtual ~Enemy();
    CMeshLoader* enemyMesh = nullptr;
    Collider* bodyCollider1 = nullptr;
    Timer* attackT = nullptr;
    int kind = 0;

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionEnter(Collider* col1, Collider* col2) override;
    virtual void onCollisionStay(Collider* col1, Collider* col2) override;
    virtual void onCollisionExit(Collider* col1, Collider* col) override;
};

