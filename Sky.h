#pragma once
#include "Object.h"
class Sky :
    public Object
{

    CMeshLoader* skyMesh = nullptr;
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionEnter(Collider* col1, Collider* col2) override;
    virtual void onCollisionExit(Collider* col1, Collider* col) override;
};

